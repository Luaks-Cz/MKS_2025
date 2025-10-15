/*
 * mainProgram.c
 *
 *  Created on: Oct 1, 2025
 *      Author: 240862
 */
#include "main.h"

uint32_t period = 300/2;

volatile uint32_t Tick = 0;
uint32_t onTime = 1000;
uint32_t offTime = 200;
enum states{
	LED_ON,
	LED_OFF
};

uint32_t off_time1 = 0;
uint32_t off_time2 = 0;

void button1();
void button2();

#define debounceTimePer 5

void mainLoop(){


	uint32_t lastPeriod = 0;
	uint8_t status = LED_OFF;

	LL_SYSTICK_EnableIT();

	while(1){
		if (status == LED_OFF){
			if (Tick > lastPeriod + onTime){
				LL_GPIO_WriteOutputPort(LED1_GPIO_Port, !LED1_Pin);
				//LL_GPIO_WriteOutputPort(GPIOx, PortValue)
				status = LED_ON;
			}
		}else{
			if (Tick > lastPeriod + onTime + offTime){

				LL_GPIO_WriteOutputPort(LED1_GPIO_Port, LED1_Pin);
				//LL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
				lastPeriod = Tick;
				status = LED_OFF;
			}
		}
		button1();
		button2();
	}
}
void button2(){
	static uint32_t lastTick = 0;
		static uint32_t old_time;
		static uint32_t debounce=0xFFFF;
		//static uint32_t old_s2;
		uint32_t new_s2 = LL_GPIO_IsInputPinSet(S1_GPIO_Port, S1_Pin);



		if (Tick > off_time1){
				LL_GPIO_ResetOutputPin(LED2_GPIO_Port, LED2_Pin);
			}

		if ((Tick - lastTick) > 5){
			debounce = debounce<<1 | new_s2;
			if (debounce == 0x7FFF){
				LL_GPIO_SetOutputPin(LED2_GPIO_Port, LED2_Pin);
				off_time1 = Tick + 100;
			}
		}
}
void button1(){
	static uint32_t lastTick = 0;
	static uint32_t old_time;
	static uint32_t debounce=0xFFFF;
	//static uint32_t old_s2;
	uint32_t new_s2 = LL_GPIO_IsInputPinSet(S2_GPIO_Port, S2_Pin);

	if (Tick > off_time1){
			LL_GPIO_ResetOutputPin(LED2_GPIO_Port, LED2_Pin);
		}

	if ((Tick - lastTick) > 5){
		debounce = debounce<<1 | new_s2;
		if (debounce == 0x7FFF){
			LL_GPIO_SetOutputPin(LED2_GPIO_Port, LED2_Pin);
			off_time1 = Tick + 1000;
		}
	}
}


/*void basicBlink(uint32_t &lastPeriod, uint8_t &status){
	if (status == LED_OFF){
		if (Tick > lastPeriod + onTime){
			LL_GPIO_WriteOutputPort(LED1_GPIO_Port, !LED1_Pin);
			//LL_GPIO_WriteOutputPort(GPIOx, PortValue)
			status = LED_ON;
		}
	}else{
		if (Tick > lastPeriod + onTime + offTime){

			LL_GPIO_WriteOutputPort(LED1_GPIO_Port, LED1_Pin);
			//LL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			lastPeriod = Tick;
			status = LED_OFF;
		}
	}
}*/
void tick(){
	Tick++;
}
void togglePinEXTI(){
	LL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
}
