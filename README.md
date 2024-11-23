# Ultrasonic-Ranging-based-on-STM32
 北京交通大学电子系统课程设计：基于STM32F103C8T6最小系统板的超声测距处理模块

## 一、编译环境与库函数
编译环境：STM32CubeIDE 1.16.0
库函数：HAL库

## 二、基本功能介绍
<figure>
<img src="https://github.com/user-attachments/assets/8ae60592-1a34-4247-8f7e-49a9995a9646" width=400/>
</figure>

系统使用移动电源通过 USB 接口采用单路+5V 直流供电,能够自动连续测量前方障碍物，测量过程中无需进行任何人工操作。


## 三、特性参数
- 理论最大测量距离：1133 cm
- 理论死区：3.46 cm (25°C）
- 理论分辨率: 0.173 mm
- 刷新率：15.87Hz
- 温度传感器精度：0.0625 °C
- 完成单次测量时间≤0.5s
- 蜂鸣器声频：420Hz

收实际电路限制，实际参数如下：
- 实际测距范围：5cm~240cm
- 实际误差范围: 5%±1cm


## 四、程序说明
- 采用多点采样取平均法稳定示数（可以尝试使用EMA算法）
- TIM1用于蜂鸣器发声
- TIM2用于实现微秒级延时
- TIM3用于实现灯条闪烁
- TIM4用于传播时长测量和输入捕获


## 五、配套电路设计原理图
![image](https://github.com/user-attachments/assets/7476bc3c-d575-4e1b-806e-a37b54973733)
![image](https://github.com/user-attachments/assets/d4fb25f1-6a45-4c1d-bd78-47037e8df418)

## 六、未来可改进方向
- 脉冲数动态变化
- 示数平滑显示算法
- OLED显示屏UI
- 远程控制模块
- 远程影像传输

>大三课设匠心巨作，特此留念


