/*
 * mainProgramFile.c
 *
 *  Created on: Jul 18, 2025
 *      Author: Luaks
 */
#include "main.h"
#include "stm32f0xx_ll_gpio.h"
#include "string.h"
#include <ctype.h>

#include "mainProgramFile.h"
#include "basicUtil.h"
#include "sct.h"

int stav = 0;
uint16_t test = 0;
void mainProgramLoop(void)
{
	sct_init();
	HAL_TIM_Encoder_Start(&htim1, htim1.Channel);

	sct_led(0x7A5C36DE);
	HAL_Delay(1000);

	HAL_TIM_Base_Start_IT(&htim3);
	while(1){

	}

}

void TIM3_callback(TIM_HandleTypeDef *htim)
{
	uint16_t newVal =  __HAL_TIM_GET_COUNTER(&htim1);
	/*test += 111;
		if (test > 1000){
			test = 0;
		}*/
	sct_value(newVal);
}
/*void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{

}*/
