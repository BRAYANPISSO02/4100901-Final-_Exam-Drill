#include "led_estatus.h"
#include "main.h"
extern UART_HandleTypeDef huart2;

uint16_t tiempo_cambio = 1;

/**
 * @brief: Esta función indica los Hz a los que debe funcionar el led.
 *
 * @param data: 1 si la contraseña es incorrecta, 0 de lo contrario.
 *
 * @retval: Ninguno.
 */
void estatus_hz (uint8_t stt){

	if (stt == 1 && HAL_GetTick() == tiempo_cambio) {
		HAL_UART_Transmit(&huart2, "Entró a incorrecto\r\n", 21, 10);
		HAL_GPIO_TogglePin(SYSTEM_LED_GPIO_Port, SYSTEM_LED_Pin);
		tiempo_cambio = HAL_GetTick() + 125;

	}else if (stt == 0 && HAL_GetTick() == tiempo_cambio){
		HAL_UART_Transmit(&huart2, "Entró a correcto\r\n", 19, 10);
		HAL_GPIO_WritePin(SYSTEM_LED_GPIO_Port, SYSTEM_LED_Pin, 1);
		tiempo_cambio = HAL_GetTick() + 125;

	}
}
