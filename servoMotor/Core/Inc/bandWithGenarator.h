/*
 * bandWithGenarator.h
 *
 *  Created on: Aug 16, 2025
 *      Author: Amin@Work
 */

#ifndef SRC_BANDWITHGENARATOR_H_
#define SRC_BANDWITHGENARATOR_H_

#include "PMW.h"

class bandWithGenarator:public PMW {
public:
	uint32_t CCR_Calculation(double);
	bandWithGenarator();
	bandWithGenarator(TIM_HandleTypeDef* ,double ,double,int8_t,uint8_t);
	void bandTimeCalculator(uint8_t);
	virtual ~bandWithGenarator();

//protected:
//uint32_t CCR_Claculation(uint8_t);
};



#endif /* SRC_BANDWITHGENARATOR_H_ */
