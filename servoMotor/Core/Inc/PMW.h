/*
 * PMW.h
 *
 *  Created on: Jul 30, 2025
 *      Author: Amin Hassani
 */
#include <main.h>
#include <stdint.h>
#ifndef SRC_PMW_H_
#define SRC_PMW_H_

class PMW {
public:
	PMW();
	PMW(TIM_HandleTypeDef*,double,double,int8_t,int8_t);
    void fire(int8_t);
	virtual ~PMW();

private:
  TIM_HandleTypeDef* pmwHandler;
  double CPU_FREQUENCY;
  int8_t DUTY_CYCLE;
  double CPU_PERIOD;
  double pmwFrequnecy;
  double pmwPeriod;
  uint32_t counterPeriodValue;
  uint32_t preScalerValue;
  uint32_t CCR;
  int8_t ACTIVE_CHANNEL;
protected:
  void doCalculation(void);

};

#endif /* SRC_PMW_H_ */
