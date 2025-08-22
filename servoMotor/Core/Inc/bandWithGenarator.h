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

	bandWithGenarator();
	bandWithGenarator(TIM_HandleTypeDef* ,double ,double,int8_t,float);
	void generateWave(double);
	virtual ~bandWithGenarator();

//protected:
//uint32_t CCR_Claculation(uint8_t);
private:
	uint32_t CCR_Calculation(double);
};



#endif /* SRC_BANDWITHGENARATOR_H_ */
