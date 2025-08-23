/*
 * servoMotor.cpp
 *
 *  Created on: Aug 23, 2025
 *      Author: Amin Hassani
 */

#include "servoMotor.h"



servoMotor::servoMotor() {
	// TODO Auto-generated destructor stub
}

servoMotor::servoMotor(TIM_HandleTypeDef* pmwGeneratorTimer, float startBand,float endBand,double pmwfreq,double cpufreq,int8_t activeCH,int8_t initAngle):bandWithGenarator(pmwGeneratorTimer,cpufreq,pmwfreq,activeCH,startBand)
{
	startBandWith = startBand;
	endBandWith = endBand;
	mapAngle2BandWtih = [this](int8_t value)
	{
		return (value/90) + this->startBandWith;
	};
    gotoAngle(initAngle);
}

void servoMotor::gotoAngle(int8_t inputAngle)
{
	if(inputAngle == angle) return;
	generateWave(mapAngle2BandWtih(inputAngle));
	angle=inputAngle;
}

servoMotor::~servoMotor() {
	// TODO Auto-generated destructor stub
}

