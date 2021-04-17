/* *************************************************************************
* File Name   :	ControllerSend.c
* Description : Send to Controller
* Functions   : 1. sendToController
* ************************************************************************* */

/* ***************************** Header Files ***************************** */
#include "../typewise-alert.h"
#include "ControllerSend.h"

/* *************************************************************************
* Function Name : sendToController
* Description   : send a alert to Controller
* Arguments	    : 1. BreachType(NORMAL / TOO_LOW / TOO_HIGH)
* Returns	      : Send Fail or Pass
* ************************************************************************* */
 SendStatus sendToController(BreachType breachType) {
   //Send to controller
  if((breachType == TOO_LOW) || (breachType == TOO_HIGH))
  {
   return CONTROLLER_SEND_PASS;
  }
  return CONTROLLER_SEND_PASS;
}
