/*
 * SerialUsartCommunication.h
 *
 *  Created on: Aug 1, 2025
 *      Author: Amin Hassani
 */
#include "malloc.h"
#include "main.h"
#include "string"
#include "iostream"
#include "algorithm"
#ifndef SRC_SERIALUSARTCOMMUNICATION_H_
#define SRC_SERIALUSARTCOMMUNICATION_H_

class SerialUsartCommunication {
public:

	static UART_HandleTypeDef* USART_HANDLER;
	static uint8_t* reciveBuffer;
	static int8_t RCV_BUFF_SIZE;
	static uint8_t* receiveCompleted(void);
	SerialUsartCommunication();
	SerialUsartCommunication(UART_HandleTypeDef*);
	void intHandler(void);
    void send(std::string , int8_t);
    void recieve(uint8_t);

	virtual ~SerialUsartCommunication();
private:
	void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
	uint8_t RCV_IDX,RCV_BYTE;
};

#endif /* SRC_SERIALUSARTCOMMUNICATION_H_ */
