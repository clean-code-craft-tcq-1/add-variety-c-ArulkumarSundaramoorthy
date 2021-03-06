/* *************************************************************************
* File Name   :	ControllerSendFake.c
* Description : Controller send fake for testing
* Functions  : 1. sendToController
* ************************************************************************* */

/* ***************************** Header Files ***************************** */
#include "../typewise-alert.h"
#include "ControllerSend.h"
#include "stdio.h"

/* *************************************************************************
* Function Name : sendToController
* Description   : send a alert to Controller
* Arguments	    : 1. BreachType(NORMAL / TOO_LOW / TOO_HIGH)
* Returns	      : Send Fail or Pass
* ************************************************************************* */
 SendStatus sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  return CONTROLLER_SEND_PASS;
}
