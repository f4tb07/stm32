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
#include "functional"
#ifndef SRC_SERIALUSARTCOMMUNICATION_H_
#define SRC_SERIALUSARTCOMMUNICATION_H_

class SerialUsartCommunication {
	//template <typename,T>
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
    int16_t IrecieveAngle(void);

	virtual ~SerialUsartCommunication();
private:
	void recieve(uint8_t,std::function<int16_t(void)>);
	void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
	uint8_t RCV_IDX,RCV_BYTE;
	//std::function<int16_t(void)> interPerter;
};

#endif /* SRC_SERIALUSARTCOMMUNICATION_H_ */
