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

/*typedef struct{
	pinStruct pin_OE;
	pinStruct pin_A;
	pinStruct pin_B;
	pinStruct pin_C;
	pinStruct pin_LAT;
	pinStruct pin_R1;
	pinStruct pin_CLK;
}HUB12_Config_t;

HUB12_Config_t HUB12_Config;*/
/*
void HUB12_init(HUB12_Config_t *pinsToSet);
void HUB12_WriteLine(uint32_t line);
*/

SCT_Config_t SCT_config;

void mainProgramLoop(void)
{
	sct_init(SCT_config);

	while(1){
		sct_led(0x7A5C36DE);
	}
	/*HUB12_init(&HUB12_Config);

	uint16_t counter = 0;
	uint32_t lineTest = 0b10101010101010101010101010101010;
	while(1)
	{
		char temp[50]= {0};
		sprintf(temp, "hello world2: %d\n", counter);
		CDC_Transmit_FS((uint8_t*)temp, strlen(temp));

		HUB12_WriteLine(lineTest);


		HAL_GPIO_WritePin(board_LED_GPIO_Port, board_LED_Pin, GPIO_PIN_SET);
		HAL_Delay(800);
		HAL_GPIO_WritePin(board_LED_GPIO_Port, board_LED_Pin, GPIO_PIN_RESET);
		HAL_Delay(800);
		counter++;
	}*/

}
/*void HUB12_init(HUB12_Config_t *pinsToSet){
	pinsToSet->pin_OE = setPinStruct(OE_GPIO_Port, OE_Pin, 1);
	pinsToSet->pin_A = setPinStruct(A_GPIO_Port, A_Pin, 1);
	pinsToSet->pin_B = setPinStruct(B_GPIO_Port, B_Pin, 1);
	pinsToSet->pin_LAT = setPinStruct(LAT_GPIO_Port, LAT_Pin, 1);
	pinsToSet->pin_R1 = setPinStruct(R1_GPIO_Port, R1_Pin, 1);
	pinsToSet->pin_CLK = setPinStruct(CLK_GPIO_Port, CLK_Pin, 1);
}
void HUB12_WriteLine(uint32_t line){

	writeToPin(&HUB12_Config.pin_OE, GPIO_PIN_RESET);

	writeToPin(&HUB12_Config.pin_A, GPIO_PIN_SET);
	writeToPin(&HUB12_Config.pin_B, GPIO_PIN_RESET);

	for (int i = 0; i < 32; i++){
		if (i%2 == 0){
			writeToPin(&HUB12_Config.pin_R1, GPIO_PIN_SET);
		}else{
			writeToPin(&HUB12_Config.pin_R1, GPIO_PIN_RESET);
		}

		writeToPin(&HUB12_Config.pin_CLK, GPIO_PIN_SET);
		HAL_Delay(100);
		writeToPin(&HUB12_Config.pin_CLK, GPIO_PIN_RESET);
		HAL_Delay(100);
	}

	writeToPin(&HUB12_Config.pin_LAT, GPIO_PIN_SET);
	HAL_Delay(100);
	writeToPin(&HUB12_Config.pin_LAT, GPIO_PIN_RESET);

	writeToPin(&HUB12_Config.pin_OE, GPIO_PIN_SET);
}*/
