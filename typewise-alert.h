/* *************************************************************************
* File Name   :	sensor-validate.h
* Description : Validate SOC & Current Readings
* Functions	  : - 
* ************************************************************************* */
#ifndef TYPEWISE_ALERT_H
#define TYPEWISE_ALERT_H
#pragma once

/* ***************************** Typedef ***************************** */
typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

typedef struct {
	double lowerLimit;
	double upperLimit;
}BatteryBreachLimit;

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

/* ***************************** Prototypes ***************************** */
void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
BreachType inferBreach(double value, double lowerLimit, double upperLimit);

#endif
