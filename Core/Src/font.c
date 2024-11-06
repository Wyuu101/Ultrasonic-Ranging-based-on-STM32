/*
 * font.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Uu
 */
#include "font.h"


uint8_t distance_16x16[8][32] ={
	/* 0 距 */ {0x00,0x3e,0x22,0xe2,0x22,0x3e,0x00,0xfe,0x22,0x22,0x22,0x22,0x22,0xe2,0x02,0x00,0x20,0x3f,0x20,0x1f,0x11,0x11,0x00,0x7f,0x44,0x44,0x44,0x44,0x44,0x47,0x40,0x00,},
	/* 1 离 */ {0x04,0x04,0x04,0xf4,0x84,0xd4,0xa5,0xa6,0xa4,0xd4,0x84,0xf4,0x04,0x04,0x04,0x00,0x00,0xfe,0x02,0x02,0x12,0x3a,0x16,0x13,0x12,0x1a,0x32,0x42,0x82,0x7e,0x00,0x00,},
	/* 2 : */ {0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
	/* 3   */ {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
	/* 4   */ {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
	/* 5   */ {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
	/* 6   */ {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
	/* 7 ㎝  */ {0x00,0x80,0x40,0x20,0x20,0x20,0x40,0x20,0xc0,0x20,0x20,0xc0,0x20,0xc0,0x00,0x00,0x00,0x07,0x08,0x10,0x10,0x10,0x08,0x00,0x1f,0x00,0x00,0x1f,0x00,0x1f,0x00,0x00,}
};

uint8_t temperature_16x16[7][32] ={
	/* 0 温 */ {0x10,0x60,0x02,0x8c,0x00,0x00,0xfe,0x92,0x92,0x92,0x92,0x92,0xfe,0x00,0x00,0x00,0x04,0x04,0x7e,0x01,0x40,0x7e,0x42,0x42,0x7e,0x42,0x7e,0x42,0x42,0x7e,0x40,0x00,},
	/* 1 度 */ {0x00,0x00,0xfc,0x24,0x24,0x24,0xfc,0x25,0x26,0x24,0xfc,0x24,0x24,0x24,0x04,0x00,0x40,0x30,0x8f,0x80,0x84,0x4c,0x55,0x25,0x25,0x25,0x55,0x4c,0x80,0x80,0x80,0x00,},
	/* 2 : */ {0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
	/* 3   */ {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
	/* 4   */ {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
	/* 5   */ {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
	/* 6 ℃ */ {0x00,0x18,0x24,0x24,0x18,0xc0,0x20,0x10,0x08,0x08,0x08,0x10,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x10,0x20,0x40,0x40,0x40,0x40,0x20,0x10,0x00,0x00,}

};

uint8_t soundSpeed_16x16[3][32] ={
	/* 0 声 */ {0x04,0x14,0xd4,0x54,0x54,0x54,0x54,0xdf,0x54,0x54,0x54,0x54,0xd4,0x14,0x04,0x00,0x80,0x60,0x1f,0x02,0x02,0x02,0x02,0x03,0x02,0x02,0x02,0x02,0x03,0x00,0x00,0x00,},
	/* 1 速 */ {0x40,0x40,0x42,0xcc,0x00,0x04,0xf4,0x94,0x94,0xff,0x94,0x94,0xf4,0x04,0x00,0x00,0x00,0x40,0x20,0x1f,0x20,0x48,0x44,0x42,0x41,0x5f,0x41,0x42,0x44,0x48,0x40,0x00,},
	/* 2 : */ {0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},

};



uint8_t numbers_16x8[11][16]={
		{0x00, 0xE0, 0x10, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x00, 0x0F, 0x10, 0x20, 0x20, 0x10, 0x0F, 0x00}, /*"0",16*/
		{0x00, 0x10, 0x10, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x3F, 0x20, 0x20, 0x00, 0x00}, /*"1",17*/
		{0x00, 0x70, 0x08, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x30, 0x28, 0x24, 0x22, 0x21, 0x30, 0x00}, /*"2",18*/
		{0x00, 0x30, 0x08, 0x88, 0x88, 0x48, 0x30, 0x00, 0x00, 0x18, 0x20, 0x20, 0x20, 0x11, 0x0E, 0x00}, /*"3",19*/
		{0x00, 0x00, 0xC0, 0x20, 0x10, 0xF8, 0x00, 0x00, 0x00, 0x07, 0x04, 0x24, 0x24, 0x3F, 0x24, 0x00}, /*"4",20*/
		{0x00, 0xF8, 0x08, 0x88, 0x88, 0x08, 0x08, 0x00, 0x00, 0x19, 0x21, 0x20, 0x20, 0x11, 0x0E, 0x00}, /*"5",21*/
		{0x00, 0xE0, 0x10, 0x88, 0x88, 0x18, 0x00, 0x00, 0x00, 0x0F, 0x11, 0x20, 0x20, 0x11, 0x0E, 0x00}, /*"6",22*/
		{0x00, 0x38, 0x08, 0x08, 0xC8, 0x38, 0x08, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00}, /*"7",23*/
		{0x00, 0x70, 0x88, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, 0x1C, 0x22, 0x21, 0x21, 0x22, 0x1C, 0x00}, /*"8",24*/
		{0x00, 0xE0, 0x10, 0x08, 0x08, 0x10, 0xE0, 0x00, 0x00, 0x00, 0x31, 0x22, 0x22, 0x11, 0x0F, 0x00}, /*"9",25*/
		 {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00} /*".",14*/
};

uint8_t soundSpeed_unit_12x12[3][24]={
	/* 0 m */ {0xf0,0x10,0x10,0xe0,0x10,0x10,0xe0,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x03,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,},
	/* 1 / */ {0x00,0xe0,0x1c,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},
	/* 2 s */ {0x20,0x50,0x50,0x90,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x02,0x02,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,}
};


uint8_t distance_sofar_16x8[6][16]={
		/* 1 > */ {0x00,0x00,0x18,0x30,0x20,0xc0,0x00,0x00,0x00,0x00,0x04,0x02,0x01,0x00,0x00,0x00,},
		/* 1 1 */ {0x00,0x00,0x10,0x0c,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,},
		/* 2 1 */ {0x00,0x00,0x10,0x0c,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,},
		/* 3 0 */ {0x00,0x00,0xf8,0x04,0x04,0xf8,0x00,0x00,0x00,0x00,0x1f,0x20,0x20,0x1f,0x00,0x00,},
		/* 4 0 */ {0x00,0x00,0xf8,0x04,0x04,0xf8,0x00,0x00,0x00,0x00,0x1f,0x20,0x20,0x1f,0x00,0x00,},
		/* 5   */ {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,},

};