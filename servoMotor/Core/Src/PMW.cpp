/*
 * PMW.cpp
 *
 *  Created on: Jul 30, 2025
 *      Author: Amin Hassani
 */

#include "PMW.h"
#include "math.h"
PMW::PMW() {
	// TODO Auto-generated constructor stub

}
PMW::PMW(TIM_HandleTypeDef* timerHandler,double cpuFreq,double pmwFreq,int8_t dutyCycle,int8_t activeCH)
{
	pmwHandler = timerHandler;
	CPU_FREQUENCY = cpuFreq;
	pmwFrequnecy = pmwFreq;
	DUTY_CYCLE = dutyCycle;
    ACTIVE_CHANNEL = activeCH;

}


PMW::PMW(TIM_HandleTypeDef* timerHandler,double cpuFreq,double pmwFreq,int8_t activeCH)
{
	pmwHandler = timerHandler;
	CPU_FREQUENCY = cpuFreq;
	pmwFrequnecy = pmwFreq;
	ACTIVE_CHANNEL = activeCH;

}

PMW::~PMW() {
	// TODO Auto-generated destructor stub
}

void PMW::doTimerCalculation()
{
	CPU_PERIOD = 1/CPU_FREQUENCY;
	pmwPeriod = 1/pmwFrequnecy;
    counterPeriodValue =floor(pmwPeriod/CPU_PERIOD) ;
    if(counterPeriodValue>65535)
    {
    	counterPeriodValue /=100;
    	preScalerValue = 100;
    }
    else
    	preScalerValue = 0;
    //CCR = counterPeriodValue * float(DUTY_CYCLE)/100;
}
uint32_t PMW::CCR_Claculation(void)
{
	return counterPeriodValue * float(DUTY_CYCLE)/100;
}


void PMW::fire(int8_t newDutyCycle)
{
  DUTY_CYCLE=newDutyCycle;
  doTimerCalculation();
  CCR = CCR_Claculation();
  pmwHandler->Instance->ARR = counterPeriodValue-1;
  pmwHandler->Instance->PSC = preScalerValue-(preScalerValue>0);
  switch (ACTIVE_CHANNEL)
  {
  	 case TIM_CHANNEL_1:
      	  pmwHandler->Instance->CCR1=CCR;
      	  break;
  	 case TIM_CHANNEL_2:
       	  pmwHandler->Instance->CCR2=CCR;
       	  break;
     case TIM_CHANNEL_3:
          pmwHandler->Instance->CCR3=CCR;
          break;
     case TIM_CHANNEL_4:
          pmwHandler->Instance->CCR4=CCR;
          break;
  }
}


double PMW::getCpuPeriod()
{
	return CPU_PERIOD;
}

void PMW::setCCR(uint32_t newCCR)
{
	CCR = newCCR;
}
