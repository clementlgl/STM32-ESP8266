/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

#include "uart_conf.h"
#include "at_esp.h"

int main(void) {
	/* Configure LED3, LED4, LED5 and LED6 */
	BSP_LED_Init(LED3);
	BSP_LED_Init(LED4);
	BSP_LED_Init(LED5);
	BSP_LED_Init(LED6);

	/* STM32F4xx HAL library initialization:
	 - Configure the Flash prefetch, instruction and Data caches
	 - Configure the Systick to generate an interrupt each 1 msec
	 - Set NVIC Group Priority to 4
	 - Global MSP (MCU Support Package) initialization
	 */
	HAL_Init();
	HAL_Delay(1000);  //Avoid ESP boot sequence

	/* Reset transmission flag */
	Uart2TxReady = Uart6TxReady = Uart2RxReady = Uart6RxReady = RESET;

	Uart_Clk_enable(6);
	Uart_Gpio_Init(6);
	Uart_Handler_Init(6);

	BSP_LED_On(LED4);


	Esp_select_mode(2);
	HAL_Delay(500);
	Esp_configure_ap("clem","1234567890");
	while(1){

	}
}
