/* *************************************************************************
* File Name   :	typewise-alert.h
* Description : typewise alert
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
  TO_EMAIL,
  TO_CONSOLE
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

typedef enum {
  SEND_FAIL,
  EMAIL_SEND_PASS,
  CONTROLLER_SEND_PASS,
  CONSOLE_SEND_PASS
} SendStatus;

/* ***************************** Prototypes ***************************** */
SendStatus checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
SendStatus sendToEmail(BreachType breachType);
SendStatus sendToConsole(BreachType breachType);
BreachType inferBreach(double value, double lowerLimit, double upperLimit);

#endif
