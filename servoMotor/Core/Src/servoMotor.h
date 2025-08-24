/*
 * servoMotor.h
 *
 *  Created on: Aug 23, 2025
 *      Author: Amin Hassani
 */

#ifndef SRC_SERVOMOTOR_H_
#define SRC_SERVOMOTOR_H_

#include <bandWithGenarator.h>
#include <functional>

class servoMotor: public bandWithGenarator {
public:
	servoMotor();
	servoMotor(TIM_HandleTypeDef*,float,float,double,double,int8_t,int16_t);
	void gotoAngle(int16_t);
	int8_t getAngle(void);
	virtual ~servoMotor();
private:
	float startBandWith;
	float endBandWith;
	int8_t angle;
	std::function<double(int16_t)> mapAngle2BandWtih;

};

#endif /* SRC_SERVOMOTOR_H_ */
