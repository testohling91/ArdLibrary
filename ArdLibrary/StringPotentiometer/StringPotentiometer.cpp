/*
 * StringPotentiometer.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: trohling
 */
#include "StringPotentiometer.h"
/* testing add text */
StringPotentiometer::StringPotentiometer(byte potPin, float potTurnCnt, float capstanDiameter, bool invertRead){
	init(potPin, potTurnCnt, capstanDiameter, invertRead);
};

StringPotentiometer::StringPotentiometer(byte potPin, float potTurnCnt, float capstanDiameter){
	init(potPin, potTurnCnt, capstanDiameter, false);
};

StringPotentiometer::~StringPotentiometer(){

};

void StringPotentiometer::init(byte potPin, float potTurnCnt, float capstanDiameter, bool invertRead) {
	m_invertRead = invertRead;
	m_potPin = potPin;
	m_capstanUnitSize =  1024 /(potTurnCnt * capstanDiameter * PI);
}

float StringPotentiometer::getMeasure(){
  int potSum = 0;
  int potReads = 5;
  
  for (int x = 0; x < potReads; x++) {
	if (m_invertRead) {
		potSum = potSum + (1023 - analogRead(m_potPin));
	} else {
		potSum = potSum + (0 + analogRead(m_potPin));
	}
		
  delay (10);
  }
  m_potValue = potSum / potReads;
  float potUnits = m_potValue / m_capstanUnitSize;
  return potUnits;
  
  };

String StringPotentiometer::setDirection(float targetMeasure) {
	float potUnits = getMeasure();
	String moveDirection = "STOP";
	if (potUnits > targetMeasure) {
		moveDirection = "DOWN";
	} else {
		if (potUnits < targetMeasure) {
			moveDirection = "UP  ";
		}
	}
	return moveDirection;
}

bool StringPotentiometer::isFinished(String moveDirection, float targetMeasure) {
	float potUnits = getMeasure();
	bool targetReached = false;
	if (moveDirection == "UP  ") {
		if (targetMeasure <= potUnits) {
			targetReached = true;
		}
	} else {
		if (moveDirection == "DOWN") {
			if (targetMeasure >= potUnits) {
				targetReached = true;
			}
		}
	}
	return targetReached;
}
