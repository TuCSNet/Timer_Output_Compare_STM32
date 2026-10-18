/*
 * retarget.c
 *
 *  Created on: Oct 18, 2026
 *      Author: vungo
 */
#include "main.h"

extern UART_HandleTypeDef huart2;
const int STDIN_FILENO = 0;
const int STDOUT_FILENO = 1;
const int STDERR_FILENO = 2;

//Print using printf in C library

int _write(int file, char* ptr, int len)
{
	if(file == STDOUT_FILENO || file == STDERR_FILENO)
	{
		HAL_StatusTypeDef  status;
		status = HAL_UART_Transmit(&huart2, (uint8_t*)ptr, len , HAL_MAX_DELAY);
		if(status == HAL_OK)
			return 1;
	}
	return -1;
}

//Get input using scanf in C library

int _read(int file, char* ptr, int len)
{
	//Convert carriage return to newline
	if (*ptr == '\r')
	{
		*ptr = '\n';
		return 1;
	}

	if(file == STDIN_FILENO)
	{
		HAL_StatusTypeDef  status;
		status = HAL_UART_Receive(&huart2, (uint8_t*) ptr, 1, HAL_MAX_DELAY);
		if (status == HAL_OK)
			return 1;
	}
	return -1;
}

