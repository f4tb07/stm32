/*
 * bandWithGenarator.cpp
 *
 *  Created on: Aug 16, 2025
 *      Author: Computer
 */

#include "bandWithGenarator.h"
#include "PMW.h"
#include "math.h"

bandWithGenarator::bandWithGenarator(TIM_HandleTypeDef* timerHandler,double cpuFreq,double pmwFreq,int8_t activeCH,float upTime)
									:PMW(timerHandler,cpuFreq,pmwFreq,activeCH)
{
	doTimerCalculation();
	timerHandler->Instance->ARR = getCounterPeriod()-1;
	timerHandler->Instance->PSC = getPreScaler() - (getPreScaler()>0);
	HAL_TIM_Base_Start(timerHandler);
    setCCR(CCR_Calculation(upTime));
	HAL_TIM_PWM_Start(timerHandler,activeCH);

}

uint32_t bandWithGenarator::CCR_Calculation(double upTime)
{
	//return floor((upTime*pow(10.0,-3.0)	)/getCpuPeriod());
	return getCounterPeriod()*((upTime*pow(10.0,-3.0))/getPMWPeriod());
}

void bandWithGenarator::generateWave(uint8_t upTime)
{

    doTimerCalculation();
	double tmpCCR =floor((upTime*pow(10.0,-6.0)	)/getCpuPeriod());
    setCCR(tmpCCR);
}

bandWithGenarator::~bandWithGenarator() {
	// TODO Auto-generated destructor stub
}

