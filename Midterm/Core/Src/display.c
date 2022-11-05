/*
 * display.c
 *
 *  Created on: Nov 1, 2022
 *      Author: dell
 */

#include "display.h"

void display7SEG(int counter) {
	/* Khoi tao mot day gom gia tri bit de hien thi cac chu so lan luot tu 0 toi 9 */
	unsigned char disp_arr[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};

	/* Khoi tao bien "varr" chua gia tri bit 7 doan cua bien "counter" de hien thi con so can hien thi va bien "bit_var" */
	unsigned char bit_var, varr = disp_arr[counter];

	/* Doi voi tung doan segment, bien bit_var se lay gia tri bit cua segment do de hien thi den (0 -> Sang, 1 -> Tat) */

	bit_var = varr & 0x01; /* Den LED7_0 */
	HAL_GPIO_WritePin(LED7_0_GPIO_Port, LED7_0_Pin, bit_var);

	bit_var = (varr>>1) & 0x01; /* Den LED7_1 */
	HAL_GPIO_WritePin(LED7_1_GPIO_Port, LED7_1_Pin, bit_var);

	bit_var = (varr>>2) & 0x01; /* Den LED7_2 */
	HAL_GPIO_WritePin(LED7_2_GPIO_Port, LED7_2_Pin, bit_var);

	bit_var = (varr>>3) & 0x01; /* Den LED7_3 */
	HAL_GPIO_WritePin(LED7_3_GPIO_Port, LED7_3_Pin, bit_var);

	bit_var = (varr>>4) & 0x01; /* Den LED7_4 */
	HAL_GPIO_WritePin(LED7_4_GPIO_Port, LED7_4_Pin, bit_var);

	bit_var = (varr>>5) & 0x01; /* Den LED7_5 */
	HAL_GPIO_WritePin(LED7_5_GPIO_Port, LED7_5_Pin, bit_var);

	bit_var = (varr>>6) & 0x01; /* Den LED7_6 */
	HAL_GPIO_WritePin(LED7_6_GPIO_Port, LED7_6_Pin, bit_var);
}
