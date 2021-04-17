/* *************************************************************************
* File Name   :	typewise-alert.c
* Description : Battery Limit check based on Cooling Type
* Functions  : 1. inferBreach
*	       2. checkAndAlert
*              3. sendToController
*	       4. sendToEmail
*	       5. sendToConsole
* ************************************************************************* */

/* ***************************** Header Files ***************************** */
#include "typewise-alert.h"
#include <stdio.h>

/* *****************************  Variables  ****************************** */
BatteryBreachLimit BatteryCoolTypeLimit[3] = {{0,35},{0,45},{0,40}};
SendStatus(*SendAlertType[])(BreachType) = { sendToController , sendToEmail, sendToConsole};
char emailAlertStr[3][10] = {"Normal","Low","High"};

/* *************************************************************************
* Function Name : inferBreach
* Description   : Check the breach limit
* Arguments	: 1. value - values for compare
*		  2. lowerLimit - another values for compare
*		  3. upperLimit - Maximum acceptable changes
* Returns	: BreachType(NORMAL / TOO_LOW / TOO_HIGH)
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
* Arguments	: 1. alertTarget - Alert type
*		  2. batteryChar - Cooling Type
*		  3. temperatureInC - Temperature value
* Returns	: Send Fail or Pass
* ************************************************************************* */
SendStatus checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
	
	SendStatus ReturnStatus = SEND_FAIL;

	BreachType breachType = inferBreach(temperatureInC, BatteryCoolTypeLimit[batteryChar.coolingType].lowerLimit, 
								BatteryCoolTypeLimit[batteryChar.coolingType].upperLimit);
	ReturnStatus = SendAlertType[alertTarget](breachType);
	
	return ReturnStatus;
}



/* *************************************************************************
* Function Name : sendToController
* Description   : send a alert to Controller
* Arguments	: 1. BreachType(NORMAL / TOO_LOW / TOO_HIGH)
* Returns	: Send Fail or Pass
* ************************************************************************* */
 SendStatus sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  return CONTROLLER_SEND_PASS;
}

/* *************************************************************************
* Function Name : sendToEmail
* Description   : send a alert via Email
* Arguments	: 1. BreachType(NORMAL / TOO_LOW / TOO_HIGH)
* Returns	: Send Fail or Pass
* ************************************************************************* */
SendStatus sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  printf("To: %s\n", recepient);

 if((breachType == TOO_LOW) || (breachType == TOO_HIGH)) {
   printf("Hi, the temperature is %s\n",emailAlertStr[breachType]);
   }
	  
 return EMAIL_SEND_PASS;
}

/* *************************************************************************
* Function Name : sendToConsole
* Description   : send a alert to Controller
* Arguments	: 1. BreachType(NORMAL / TOO_LOW / TOO_HIGH)
* Returns	: Send Fail or Pass
* ************************************************************************* */
 SendStatus sendToConsole(BreachType breachType) {
  printf("Console : %x\n", breachType);
  return CONSOLE_SEND_PASS;
}
