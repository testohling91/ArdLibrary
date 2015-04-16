/*
 * StringPotentiometer.h
 *
 *  Created on: Mar 30, 2015
 *      Author: trohling
 */

#ifndef STRINGPOTENTIOMETER_H_
#define STRINGPOTENTIOMETER_H_

#include "Arduino.h"

class StringPotentiometer {
public:
	StringPotentiometer(byte potPin, float potTurnCnt, float capstanDiameter, bool invertRead);
	StringPotentiometer(byte potPin, float potTurnCnt, float capstanDiameter);
	~StringPotentiometer();
	float getMeasure();
	String setDirection(float targetMeasure);
	bool isFinished(String moveDirection, float targetMeasure);
	
	void init(byte potPin, float potTurnCnt, float capstanDiameter, bool invertRead);
	
private:
	bool m_invertRead;
	byte m_potPin;
	float m_capstanUnitSize;
	int m_prev_potValue;
	int m_potValue;

};


#endif /* STRINGPOTENTIOMETER_H_ */
