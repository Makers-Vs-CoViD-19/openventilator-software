/*
 * Funtions for the Potentiometers
 */

#include "potentiometer.h"

potentiometer::potentiometer(uint8_t potiPin, uint8_t gradiations){
	pinMode(potiPin, INPUT);
	this->gradiations = gradiations;
	this->potiPin = potiPin;
}
uint8_t potentiometer::getValue(uint8_t prevValue){
	this->prevValue = prevValue;
	this->value = map(analogRead(potiPin), 5, 1020, 1, gradiations);
	// only from 5 to 1020 because the risk of bit jitter in the upper and lower range Part
	return value;
}
bool potentiometer::isTurned(){
	Serial.print("potentiometer ");
	Serial.print(potiPin);
	Serial.print(": ");
	Serial.println(value);
	if(value != prevValue) return true;
	else return false;
}
