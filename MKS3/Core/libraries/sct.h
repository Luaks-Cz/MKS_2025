/*
 * sct.h
 *
 *  Created on: Oct 8, 2025
 *      Author: Luaks
 */

#ifndef LIBRARIES_SCT_H_
#define LIBRARIES_SCT_H_

typedef struct{
	pinStruct NLA;
	pinStruct SDI;
	pinStruct CLK;
	pinStruct NOE;
}SCT_Config_t;

uint8_t sct_init();
uint8_t sct_led(uint32_t value);
uint8_t sct_value(uint16_t value);

#endif /* LIBRARIES_SCT_H_ */
