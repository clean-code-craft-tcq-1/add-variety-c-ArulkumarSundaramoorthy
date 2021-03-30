/* *************************************************************************
* File Name   :	typewise-alert.c
* Description : Battery Limit check based on Cooling Type
* Functions	  : 1. inferBreach
*				2. checkAndAlert
*				3. sendToController
*				4. sendToEmail
* ************************************************************************* */

/* ***************************** Header Files ***************************** */
#include "typewise-alert.h"
#include <stdio.h>

/* *****************************  Variables  ****************************** */
BatteryBreachLimit BatteryCoolTypeLimit[3] = {{0,35},{0,45},{0,40}};

/* *************************************************************************
* Function Name : inferBreach
* Description   : Check the breach limit
* Arguments	    : 1. value - values for compare
*				  2. lowerLimit - another values for compare
*				  3. upperLimit - Maximum acceptable changes
* Returns		: BreachType(NORMAL / TOO_LOW / TOO_HIGH)
* ************************************************************************* */
BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

/* *************************************************************************
* Function Name : checkAndAlert
* Description   : Check the breach limit & send a alert
* Arguments	    : 1. alertTarget - Alert type
*				  2. batteryChar - Cooling Type
*				  3. temperatureInC - Temperature value
* Returns		: -
* ************************************************************************* */
void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

	BreachType breachType = inferBreach(temperatureInC, BatteryCoolTypeLimit[batteryChar.coolingType].lowerLimit, 
								BatteryCoolTypeLimit[batteryChar.coolingType].upperLimit);

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

/* *************************************************************************
* Function Name : sendToController
* Description   : send a alert to Controller
* Arguments	    : 1. BreachType(NORMAL / TOO_LOW / TOO_HIGH)
* Returns		: -
* ************************************************************************* */
void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

/* *************************************************************************
* Function Name : sendToEmail
* Description   : send a alert via Email
* Arguments	    : 1. BreachType(NORMAL / TOO_LOW / TOO_HIGH)
* Returns		: -
* ************************************************************************* */
void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  switch(breachType) {
    case TOO_LOW:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
      break;
    case TOO_HIGH:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
      break;
    case NORMAL:
      break;
  }
}
