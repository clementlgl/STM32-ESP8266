#include "at_esp.h"

uint8_t SendATCommand(char *cmd);

uint8_t Esp_connect(uint8_t *ssid, uint8_t *password){



	return 0;
}

void Esp_select_mode(int mode){
	char cmd[15] ="";
	sprintf(cmd,"AT+CWMODE=%i\r\n",mode);
	SendATCommand(cmd);
}

void Esp_configure_ap(char *ssid, char *password){
	char cmd[40] = "";
	sprintf(cmd, "AT+CWSAP=\"%s\",\"%s\",5,3\r\n",ssid,password);
	SendATCommand(cmd);
}

uint8_t SendATCommand(char *cmd) {
	Uart6TxReady = RESET;

	if (HAL_UART_Transmit_IT(&UartHandle6, (uint8_t *) cmd, strlen(cmd)) != HAL_OK) {
		Error_Handler();
	}

	while (Uart6TxReady != SET) {
	}

	return 1;
}
