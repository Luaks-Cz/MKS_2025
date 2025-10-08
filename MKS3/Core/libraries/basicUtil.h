/*
 * basicUtil.h
 *
 *  Created on: Sep 27, 2025
 *      Author: Luaks
 */

#ifndef LIBRARIES_BASICUTIL_H_
#define LIBRARIES_BASICUTIL_H_


#include "stm32f0xx_ll_gpio.h"

typedef struct {
	GPIO_TypeDef *port;
	uint16_t pin;
	uint8_t polarity;
	uint8_t state;//sas

} pinStruct;

pinStruct setPinStruct(GPIO_TypeDef *GPIO_port, uint16_t pinNum, uint8_t pinPolarity);
void writeToPin(pinStruct *pinToChange, uint8_t state);

#endif /* LIBRARIES_BASICUTIL_H_ */
