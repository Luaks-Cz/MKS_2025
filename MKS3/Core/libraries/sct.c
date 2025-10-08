/*
 * sct.c
 *
 *  Created on: Oct 8, 2025
 *      Author: Luaks
 */
#include "basicUtil.h"
#include "main.h"
#include "stdint.h"
#include "sct.h"


uint8_t sct_init(SCT_Config_t *NewConfigStruct){
	NewConfigStruct->NLA = setPinStruct(SCT_NLA_GPIO_Port,SCT_NLA_Pin, 1);
	NewConfigStruct->SDI = setPinStruct(SCT_SDI_GPIO_Port,SCT_SDI_Pin, 1);
	NewConfigStruct->CLK = setPinStruct(SCT_CLK_GPIO_Port,SCT_CLK_Pin, 1);
	NewConfigStruct->NOE = setPinStruct(SCT_NOE_GPIO_Port,SCT_NOE_Pin, 1);
	return 0;
}
uint8_t sct_led(uint32_t value){

	return 0;
}
uint8_t sct_value(uint16_t value){

	return 0;
}
