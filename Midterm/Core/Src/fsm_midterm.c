/*
 * fsm_manual.c
 *
 *  Created on: Nov 6, 2022
 *      Author: user
 */

#include "fsm_midterm.h"

void led_blinky() {
	if (timer_flag[1] == 1) {
		setTimer(1, 500);
		HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
	}
}

void fsm_simple_buttons_run() {
	switch(status) {
	case INIT:
		display7SEG(counter);
		status = CURRENT;
		break;

	case CURRENT:
		display7SEG(counter);
		if (isButtonPressed(0) == 1) {
			status = RESET_STATE;
			setTimer(0, 10000);
		}
		if (isButtonPressed(1) == 1) {
			status = ADD;
			setTimer(0, 10000);
		}
		if (isButtonPressed(2) == 1) {
			status = SUB;
			setTimer(0, 10000);
		}
		if (timer_flag[0] == 1) {
			status = AUTO;
		}
		break;

	case RESET_STATE:
		counter = 0;
		display7SEG(counter);
		status = CURRENT;
		break;

	case ADD:
		counter++;
		if (counter > 9) counter = 0;
		display7SEG(counter);
		status = CURRENT;
		break;

	case SUB:
		counter--;
		if (counter < 0) counter = 9;
		display7SEG(counter);
		status = CURRENT;
		break;

	case AUTO:
		if (counter > 0) counter--;

		display7SEG(counter);
		setTimer(0,1000);
		status = CURRENT;
		if (isButtonPressed(0) == 1) {
			status = RESET_STATE;
			setTimer(0, 10000);
		}
		if (isButtonPressed(1) == 1) {
			status = ADD;
			setTimer(0, 10000);
		}
		if (isButtonPressed(2) == 1) {
			status = SUB;
			setTimer(0, 10000);
		}
		break;

	default:
		break;
	}
}
