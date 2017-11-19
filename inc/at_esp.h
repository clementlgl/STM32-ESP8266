#ifndef __AT_ESP_H
#define __AT_ESP_H

#include "stm32f4xx_hal.h"
#include "stm32f4_discovery.h"
#include "uart_conf.h"

/* UART status declaration */
//extern volatile ITStatus Uart2TxReady, Uart6TxReady, Uart2RxReady, Uart6RxReady;

/* UART handler declaration */
//extern UART_HandleTypeDef UartHandle2, UartHandle6;	//Declare a UART_HandleTypeDef handle structures.


uint8_t Esp_connect(uint8_t *ssid, uint8_t *password);
void Esp_select_mode(int mode);
void Esp_configure_ap(char *ssid, char *password);

#endif
