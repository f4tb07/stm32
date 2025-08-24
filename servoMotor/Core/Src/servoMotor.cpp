/*
 * servoMotor.cpp
 *
 *  Created on: Aug 23, 2025
 *      Author: Amin Hassani
 */

#include "servoMotor.h"


double tmp;
servoMotor::servoMotor() {
	// TODO Auto-generated destructor stub
}

servoMotor::servoMotor(TIM_HandleTypeDef* pmwGeneratorTimer, float startBand,float endBand,double pmwfreq,double cpufreq,int8_t activeCH,int16_t initAngle):bandWithGenarator(pmwGeneratorTimer,cpufreq,pmwfreq,activeCH,startBand)
{
	startBandWith = startBand;
	endBandWith = endBand;
	mapAngle2BandWtih = [this](int16_t value)
	{
		//tmp=double(value)/90; //+ this->startBandWith;
		return (double(value)/90) + this->startBandWith;
	};
    gotoAngle(initAngle);
}

int8_t servoMotor::getAngle(void){
	return angle;
}

void servoMotor::gotoAngle(int16_t inputAngle)
{
	if(inputAngle == angle) return;
    tmp = mapAngle2BandWtih(inputAngle);
	generateWave(tmp);
	angle=inputAngle;
}

servoMotor::~servoMotor() {
	// TODO Auto-generated destructor stub
}

