/*
 * SerialUsartCommunication.cpp
 *
 *  Created on: Aug 1, 2025
 *      Author: Amin Hassani
 */

#include "SerialUsartCommunication.h"
#include "string.h"
#include "stdio.h"
//#include "stm32g0xx_hal_uart.h"

UART_HandleTypeDef* SerialUsartCommunication::USART_HANDLER ;
uint8_t* SerialUsartCommunication::reciveBuffer;
int8_t SerialUsartCommunication::RCV_BUFF_SIZE ;
uint8_t rcvByte[2];
int rcvIdx=0;
//auto interPerter=0;
template <typename T>
std::function<T()> interPerter;



SerialUsartCommunication::SerialUsartCommunication() {
	// TODO Auto-generated constructor stub

}

SerialUsartCommunication::SerialUsartCommunication(
		UART_HandleTypeDef* usartHandle)
{
	USART_HANDLER = usartHandle;

}



void SerialUsartCommunication::send(std::string message, int8_t timeOut)
{
	uint8_t* tmpCharMemPtr = (uint8_t*) malloc(message.size()+1);

    for(int i=0;i<static_cast<int>(message.size());i++)
    {
    	tmpCharMemPtr[i]=message[i];
    }
    tmpCharMemPtr[message.size()]='\0';
    HAL_UART_Transmit(USART_HANDLER, tmpCharMemPtr, message.size(),timeOut);
    free(tmpCharMemPtr);
}


void echo( int8_t timeOut)
{
	uint8_t* tmpCharMemPtr = (uint8_t*) malloc(SerialUsartCommunication::RCV_BUFF_SIZE);
	memcpy(tmpCharMemPtr,SerialUsartCommunication::reciveBuffer,SerialUsartCommunication::RCV_BUFF_SIZE);
    HAL_UART_Transmit(SerialUsartCommunication::USART_HANDLER, tmpCharMemPtr, SerialUsartCommunication::RCV_BUFF_SIZE,timeOut);
    free(tmpCharMemPtr);
}


extern "C"
{

	void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
	{

		    memcpy(SerialUsartCommunication::reciveBuffer+rcvIdx,rcvByte,1);
		    if(HAL_UART_Receive_IT(SerialUsartCommunication::USART_HANDLER,rcvByte ,1)!= HAL_BUSY && ++rcvIdx>=SerialUsartCommunication::RCV_BUFF_SIZE)
		    		    {
		    		    	SerialUsartCommunication::receiveCompleted ();
		    		    	rcvIdx=0;
		    		    }


	}
}

void SerialUsartCommunication::recieve(uint8_t rcvBuffSize,std::function<int16_t(void)> recieveType)
{

	if(rcvBuffSize>0)
		{
		RCV_BUFF_SIZE = rcvBuffSize;
		reciveBuffer = 	(uint8_t*) malloc(rcvBuffSize);
					if(!reciveBuffer)
						delete this;
		}
		rcvIdx=0;
		HAL_UART_Receive_IT(USART_HANDLER, rcvByte, 1);
}

int16_t SerialUsartCommunication::IrecieveAngle()
{

    std::function<int16_t()> interPerter;
	interPerter = [this]()
	{
		int16_t angle;
		uint8_t* tmpCharMemPtr = (uint8_t*) malloc(this->RCV_BUFF_SIZE);
		memcpy(tmpCharMemPtr,this->reciveBuffer,this->RCV_BUFF_SIZE);
		free(this->reciveBuffer);
		if(tmpCharMemPtr[0]=='<' && tmpCharMemPtr[this->RCV_BUFF_SIZE-1]=='>')
		    {
		    	int16_t hunderd=tmpCharMemPtr[1]*100;
		    	int16_t ten=tmpCharMemPtr[2]*10;
		    	angle = hunderd + ten + tmpCharMemPtr[3];
		    }
		return angle;
	};
	//recieve(5,interPerter);r
}


uint8_t* SerialUsartCommunication::receiveCompleted ()
{

	if(rcvIdx>=RCV_BUFF_SIZE)
		{
		     HAL_UART_AbortReceive(USART_HANDLER);
		     //interPerter();
			 return reciveBuffer; //here we have a mem allocation which is not freed. And must mange
		}
	else
		return 0;
}



SerialUsartCommunication::~SerialUsartCommunication() {
	// TODO Auto-generated destructor stub
}

