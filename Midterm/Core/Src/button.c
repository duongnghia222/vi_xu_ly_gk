/*
 * button.c
 *
 *  Created on: Oct 7, 2022
 *      Author: user
 */

#include "button.h"


int KeyReg0[NUM_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg1[NUM_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg2[NUM_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg3[NUM_OF_BUTTONS] = {NORMAL_STATE};

int button_flag[NUM_OF_BUTTONS] = {0};
int buttonlong_flag[NUM_OF_BUTTONS] = {0};

int TimeOutForKeyPress[NUM_OF_BUTTONS] = {TIMEOUTFORLONGKEYPRESS};

int isButtonPressed(int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	button_flag[index] = 1;
}

void getKeyInput() {
	for (int i = 0; i < NUM_OF_BUTTONS; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];

		if (i == 0) {
			KeyReg2[i] = HAL_GPIO_ReadPin(RES_GPIO_Port, RES_Pin);
		}
		else if (i == 1) {
			KeyReg2[i] = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
		}
		else if (i == 2) {
			KeyReg2[i] = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
		}

		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE){
					subKeyProcess(i);
					if (buttonlong_flag[i] == 0) {
						TimeOutForKeyPress[i] = TIMEOUTFORLONGKEYPRESS;
					}
					else {
						TimeOutForKeyPress[i] = 1000 / TIME_CYCLE;
					}
				}
			} else {
				TimeOutForKeyPress[i]--;

				if (TimeOutForKeyPress[i] == 0){
					KeyReg3[i] = NORMAL_STATE;
					buttonlong_flag[i] = 1;
				}
			}
		}
		else {
			buttonlong_flag[i] = 0;
		}
	}
}

