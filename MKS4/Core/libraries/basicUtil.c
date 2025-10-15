/*
 * basicUtil.c
 *
 *  Created on: Sep 27, 2025
 *      Author: Luaks
 */
#include "main.h"
#include "mainProgramFile.h"
#include "basicUtil.h"
#include "stm32f0xx_HAL_gpio.h"

pinStruct setPinStruct(GPIO_TypeDef *GPIO_port, uint16_t pinNum, uint8_t pinPolarity){
	pinStruct newGPIO;
	newGPIO.port = GPIO_port;
	newGPIO.pin = pinNum;
	newGPIO.state = 0;
	newGPIO.polarity = pinPolarity;

	return newGPIO;
}

void writeToPin(pinStruct *pinToChange, uint8_t state){

	uint8_t physical = state ^ (pinToChange->polarity ? 0 : 1);
	HAL_GPIO_WritePin(pinToChange->port, pinToChange->pin, physical);
	/*if (physical){
		LL_GPIO_SetOutputPin(pinToChange->port, pinToChange->pin);
	}
	else{
		LL_GPIO_ResetOutputPin(pinToChange->port, pinToChange->pin);
	}*/


	pinToChange->state = state; // remember logical state
}
