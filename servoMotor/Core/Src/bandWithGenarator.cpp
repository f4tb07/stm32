/*
 * bandWithGenarator.cpp
 *
 *  Created on: Aug 16, 2025
 *      Author: Computer
 */

#include "bandWithGenarator.h"

bandWithGenarator::bandWithGenarator(TIM_HandleTypeDef* timerHandler,double cpuFreq,double pmwFreq,int8_t dutyCycle,int8_t activeCH)
									:PMW(timerHandler,cpuFreq,pmwFreq,dutyCycle,activeCH)
{
	// TODO Auto-generated constructor stub

}

bandWithGenarator::~bandWithGenarator() {
	// TODO Auto-generated destructor stub
}

