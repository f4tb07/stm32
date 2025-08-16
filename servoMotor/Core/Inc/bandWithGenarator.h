/*
 * bandWithGenarator.h
 *
 *  Created on: Aug 16, 2025
 *      Author: Amin@Work
 */

#ifndef SRC_BANDWITHGENARATOR_H_
#define SRC_BANDWITHGENARATOR_H_

#include "PMW.h"

class bandWithGenarator:PMW {
public:
	bandWithGenarator();
	bandWithGenarator(TIM_HandleTypeDef* ,double ,double,int8_t,int8_t );
	void bandTimeCalculator(double);
	virtual ~bandWithGenarator();
};

#endif /* SRC_BANDWITHGENARATOR_H_ */
