#include "led_estatus.h"
#include "main.h"

void estatus_hz (uint8_t stt){

	uint16_t last_press_tick = 0;
	if (stt == 1 && HAL_GetTick() > (last_press_tick + 125)) {

		HAL_GPIO_TogglePin(SYSTEM_LED_GPIO_Port, SYSTEM_LED_Pin);
		last_press_tick = HAL_GetTick();

	}else{
		HAL_GPIO_WritePin(SYSTEM_LED_GPIO_Port, SYSTEM_LED_Pin);
	}
}
