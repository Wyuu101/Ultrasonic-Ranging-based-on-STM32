/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "iwdg.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "burst.h"
#include "delay.h"
#include "stdio.h"
#include "string.h"
#include "oled.h"
#include "ds18b20.h"
#include "stdint.h"
#include "lightbar.h"
#include "distanceProc.h"
#include "beep.h"
#include "iwdg.h"
#include "math.h"
#include "queue.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SOFT_FILTER 1	//软件滤波(1即为不启动)
#define LOOP_INTERVAL 63 //主循环延时，主要体现在OLED刷新率和脉冲间隔,单位毫秒
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
//触发定时器更新中断时定时器并不会停止计数，需要手动停停止
//停止定时器输入捕获并不会停止定时器的计数。
void  HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	//TIM1用于蜂鸣器发声
	if(htim == &htim1){
		//距离适当
		if(!beep_too_close){
			if(__HAL_TIM_GET_AUTORELOAD(&htim1)== BEEP_FREQUENCY_AUTORELOAD){
				//先关闭定时器中断
				HAL_TIM_Base_Stop_IT(&htim1);
				if(beep_rounds<BEEP_ROUNDS*2){
					HAL_GPIO_TogglePin(BEEP_GPIO_Port, BEEP_Pin);
					beep_rounds++;
					//继续启动计数器
				}
				else{
					//如果已完成十次脉冲，就进入延时阶段
					beep_rounds=0;
					//设置重复计数寄存器RCR
					TIM1->RCR = beep_interval_rounds_tre-1;
					//设置计时器重装初值为3999，这样一次溢出就消耗4ms
					__HAL_TIM_SET_AUTORELOAD(&htim1,3999);
				}
			}
			//如果中断产生时，定时器处于的是延时模式，就切换回脉冲
			else if(__HAL_TIM_GET_AUTORELOAD(&htim1)== 3999){
				//先关闭定时器，以防设置重装初值时跑飞
				HAL_TIM_Base_Stop_IT(&htim1);
				//清零RCR（重复计数寄存器）
				TIM1->RCR =0;
				//设置定时器重装值
				__HAL_TIM_SET_AUTORELOAD(&htim1,BEEP_FREQUENCY_AUTORELOAD);
			}
			//设置计数值为0后再重新打开定时器
			__HAL_TIM_SET_COUNTER(&htim1,0);
			//启动计时器
			HAL_TIM_Base_Start_IT(&htim1);
		}
		//距离过近，切换为长鸣
		else{
			HAL_TIM_Base_Stop_IT(&htim1);
			HAL_GPIO_TogglePin(BEEP_GPIO_Port, BEEP_Pin);
			//设置计数值为0后再重新打开定时器
			__HAL_TIM_SET_COUNTER(&htim1,0);
			//启动计时器
			HAL_TIM_Base_Start_IT(&htim1);
		}
	}
	//TIM3用于实现灯条闪烁
	else if(htim == &htim3){
		Toggle_LightBar();
	}
	//TIM4用于实现距离测量计时
	else if(htim ==&htim4){
		timeout =1;
	}
}




/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_TIM4_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_IWDG_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  //初始化OLED
  OLED_Init();
  //清空OLED屏幕
  OLED_ClearScreen();
  //显示静态的文本
  OLED_SoundSpeed_Text();
  OLED_ShowTemperature_Text();
  OLED_ShowDistance_Text();
  OLED_SoundSpeed_Unit();
  //启动IWDG独立看门狗40Khz进行32分频，初值4000，超时时间3.2s
  HAL_IWDG_Init(&hiwdg);
  //初始化一个全局队列，用于数据平滑处理
  initQueue(&globalQueue);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
	  //喂狗
	  HAL_IWDG_Refresh(&hiwdg);
	  //如果DS18B20不在线，就阻塞整个程序
	  if(!ds18b20_online){
		  while(1){
			  HAL_Delay(1000);
		  }
	  }
	  //清空TIM4计数器
	  __HAL_TIM_SET_COUNTER(&htim4,0);
	  //测距成功标志位清0
	  success =0;
	  //清空ccr1标志位
	  __HAL_TIM_CLEAR_FLAG(&htim4,TIM_FLAG_CC1);
	  //复位超时标志位
	  timeout  = 0;
	  //赋值一个用于判断超时的时间节点
	  uint32_t expireTime = HAL_GetTick()+LOOP_INTERVAL;
	  //软件滤波的缓存
	  uint8_t filter_counts = 0;
	  //启动定时器4并打开中断
	  HAL_TIM_Base_Start_IT(&htim4);
	  //发射脉冲
	  Burst_Signal();
	  //用于屏蔽探头间声波串扰，这将影响雷达死区
	  //Delay_us(150);
	  //打开TIM4输入捕获功能，通道1
	  HAL_TIM_IC_Start(&htim4, TIM_CHANNEL_1);

	  //如果未超时，就一直循环检测输入捕获寄存器
	  while(!timeout){
		  //如果标志位被置位并且计数器未溢出，说明已经捕获到回声，可以跳出循环进行下一步处理
		  if(__HAL_TIM_GET_FLAG(&htim4,TIM_FLAG_CC1)){
			  filter_counts++;
			  //如果捕获的次数大于软件滤波阈值，则代表捕获到有效信号
			  if(filter_counts>=SOFT_FILTER){
				  //先关闭TIM4定时器输入捕获
				  HAL_TIM_IC_Stop(&htim4, TIM_CHANNEL_1);
				  //再关闭TIM4定时器计数和中断功能
				  HAL_TIM_Base_Stop_IT(&htim4);
				  //标记测距成功
				  success=1;
				  break;
			  }
			  //清空CCR1标志位
			  __HAL_TIM_CLEAR_FLAG(&htim4,TIM_FLAG_CC1);
		  }
	  }
	  //先关闭TIM4定时器输入捕获
	  HAL_TIM_IC_Stop(&htim4, TIM_CHANNEL_1);
	  //再关闭TIM4定时器计数和中断功能
	  HAL_TIM_Base_Stop_IT(&htim4);
	  //如果测距成功，就开始进行距离计算
	  if(success){
		  Distance_Caculate();
		  if(distance<10){
			  sprintf(distance_msg,"%.4f\n",distance);
		  }
		  else{
			  sprintf(distance_msg,"%.3f\n",distance);
		  }
		  OLED_ShowDistance((uint8_t*)distance_msg);
		  //确保每次猝发信号的间隔一致
		  if(HAL_GetTick()<expireTime){
			  HAL_Delay(expireTime-HAL_GetTick());
		  }
	  }
	  //如果测距不成功
	  else{
		  //如果队列不为空
		  if(!isQueueEmpty(&globalQueue)){
			  //如果距离过远出现次数在3次以下，判定为偶然情况，继续显示上一次距离
			  if(count_toofar<=3){
				  distance = queueAverage(&globalQueue);
				  count_toofar++;
				  if(distance<10){
					  sprintf(distance_msg,"%.4f\n",distance);
				  }
				  else{
					  sprintf(distance_msg,"%.3f\n",distance);
				  }
				  OLED_ShowDistance((uint8_t*)distance_msg);
			  }
			  //距离过远次数出现在3次以上，判定为确实超出测量范围
			  else{
				  distance =1100;
				  clearQueue(&globalQueue);
				  OLED_ShowDistance_SoFar();
				  count_toofar=0;
			  }
		  }
		  //如果队列为空，直接打印距离过远
		  else{
			  //复位距离过远记录次数
			  count_toofar=0;
			  distance =1100;
			  //在显示屏打印距离过远的文字
			  OLED_ShowDistance_SoFar();
		  }
	  }

	  //变换灯条
	  Change_LightBar();
	  //变换蜂鸣频率等参数->具体要靠中断
	  Beep();
	  //测温状态机
	  DS18B20_ReadTemperature();
	  //运行状态灯
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {

  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
