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

SCT_Config_t SCT_config;

static const uint32_t reg_values[3][10] = {
		{
				//PCDE--------GFAB @ DIS1
				0b0111000000000111 << 16,
				0b0100000000000001 << 16,
				0b0011000000001011 << 16,
				0b0110000000001011 << 16,
				0b0100000000001101 << 16,
				0b0110000000001110 << 16,
				0b0111000000001110 << 16,
				0b0100000000000011 << 16,
				0b0111000000001111 << 16,
				0b0110000000001111 << 16,
		},
		{
				//----PCDEGFAB---- @ DIS2
				0b0000011101110000 << 0,
				0b0000010000010000 << 0,
				0b0000001110110000 << 0,
				0b0000011010110000 << 0,
				0b0000010011010000 << 0,
				0b0000011011100000 << 0,
				0b0000011111100000 << 0,
				0b0000010000110000 << 0,
				0b0000011111110000 << 0,
				0b0000011011110000 << 0,
		},
		{
				//PCDE--------GFAB @ DIS3
				0b0111000000000111 << 0,
				0b0100000000000001 << 0,
				0b0011000000001011 << 0,
				0b0110000000001011 << 0,
				0b0100000000001101 << 0,
				0b0110000000001110 << 0,
				0b0111000000001110 << 0,
				0b0100000000000011 << 0,
				0b0111000000001111 << 0,
				0b0110000000001111 << 0,
		},
};


uint8_t sct_init(){
	SCT_config.NLA = setPinStruct(SCT_NLA_GPIO_Port,SCT_NLA_Pin, 1);
	SCT_config.SDI = setPinStruct(SCT_SDI_GPIO_Port,SCT_SDI_Pin, 1);
	SCT_config.CLK = setPinStruct(SCT_CLK_GPIO_Port,SCT_CLK_Pin, 1);
	SCT_config.NOE = setPinStruct(SCT_NOE_GPIO_Port,SCT_NOE_Pin, 1);
	return 0;
}
uint8_t sct_led(uint32_t value){
	for (int i = 0; i <32; i++){
		if (value & 1){
			writeToPin(&SCT_config.SDI, 1);
		}else{
			writeToPin(&SCT_config.SDI, 0);
		}
		value >>= 1;
		writeToPin(&SCT_config.CLK, 1);
		writeToPin(&SCT_config.CLK, 0);
	}
	writeToPin(&SCT_config.NLA, 1);
	writeToPin(&SCT_config.NLA, 0);
	return 0;
}
uint8_t sct_value(uint16_t value){
	uint32_t reg = 0;
	reg |= reg_values[0][(value / 100 )% 10];
	reg |= reg_values[1][(value / 10 )% 10];
	reg |= reg_values[2][value % 10];
	sct_led(reg);
	return 0;
}
