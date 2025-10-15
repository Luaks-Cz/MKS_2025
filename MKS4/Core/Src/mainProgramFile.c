/*
 * mainProgramFile.c
 *
 *  Created on: Jul 18, 2025
 *      Author: Luaks
 */
#include "main.h"
//#include "stm32f0xx_ll_gpio.h"
#include "string.h"
#include <ctype.h>

#include "mainProgramFile.h"
#include "basicUtil.h"
#include "sct.h"

int stav = 0;
uint16_t test = 0;

uint32_t rawADCData[3] = {0};
uint8_t adcDoneFlag = 0;

#define apply_Q(x) ((x) >> 6)
static volatile uint32_t value_avg = 0;
static enum {SHOW_POT, SHOW_VOLT, SHOW_TEMP} state = SHOW_POT;

#define TEMP110_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7C2))
#define TEMP30_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7B8))

#define VREFINT_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7BA))


void mainProgramLoop(void)
{

	sct_init();
	sct_led(0x7A5C36DE);

	HAL_ADCEx_Calibration_Start(&hadc);
	HAL_ADC_Start_IT(&hadc);
	//HAL_ADC_Start_DMA(&hadc, (uint32_t*)rawADCData, 1);

	HAL_Delay(1000);
	uint32_t lastChange = HAL_GetTick();

	while(1){
		if (adcDoneFlag){

			uint16_t displayVal = (500.0/4095.0)*rawADCData[0];
			uint8_t ledCount = (displayVal)*(9.0/500.0);
			if (state == SHOW_POT){

			}else if (state == SHOW_VOLT){
				uint32_t voltage = 330 * (*VREFINT_CAL_ADDR) / rawADCData[2];
				displayVal = voltage;
			}else if (state == SHOW_TEMP){
				int32_t temperature = (rawADCData[1] - (int32_t)(*TEMP30_CAL_ADDR));
				temperature = temperature * (int32_t)(110 - 30);
				temperature = temperature / (int32_t)(*TEMP110_CAL_ADDR - *TEMP30_CAL_ADDR);
				temperature = temperature + 30;
				displayVal = temperature;
			}

			//sct_value(displayVal);

			sct_valuePlus(displayVal, ledCount);
			adcDoneFlag = 0;
		}




		if (!HAL_GPIO_ReadPin(S1_GPIO_Port, S1_Pin)&&(state == SHOW_POT)){
			state = SHOW_TEMP;
			lastChange = HAL_GetTick();
		}
		if (!HAL_GPIO_ReadPin(S2_GPIO_Port, S2_Pin)&&(state == SHOW_POT)){
			state = SHOW_VOLT;
			lastChange = HAL_GetTick();
		}
		if ((HAL_GetTick() - lastChange)  > 1000){
			state = SHOW_POT;
		}

	}

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc){
	static uint32_t avg_pot[3] = {0};
	static uint8_t channel = 0;

	//rawADCData = HAL_ADC_GetValue(hadc);
	rawADCData[channel]  = apply_Q(avg_pot[channel]);
	avg_pot[channel] -= rawADCData[channel] ;
	avg_pot[channel]  += HAL_ADC_GetValue(hadc);

	adcDoneFlag = 1;

	if (__HAL_ADC_GET_FLAG(hadc, ADC_FLAG_EOS)) channel = 0;
	else channel++;

}

