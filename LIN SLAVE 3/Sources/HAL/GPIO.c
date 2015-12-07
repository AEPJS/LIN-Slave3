/*
 * GPIO.c
 *
 *  Created on: Nov 19, 2015
 *      Author: PUG
 */
/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: GPIO.c $
 * $Revision: A $
 * $Author: Benjamin Aguilar $
 * $Date: 19/11/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** Configuration of input push buttons and macros
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/*                     | LIN SLAVE 3        |       1.0                       */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: GPIO.h  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "HAL/GPIO.h"


/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/
void GPIO_config(void)
{  
    /* Set LED as OUTPUT*/
  		SIU.PCR[68].R = 0x200;	  	
  		/* Configure pad PB2 for AF1 func: LIN0TX */
  		    SIU.PCR[18].B.SRC = 1; 
  		    SIU.PCR[18].B.OBE = 1;
  		    SIU.PCR[18].B.PA = 1; 
  		/* Configure pad PB3 for LIN0RX */    
  		    SIU.PCR[19].B.IBE = 1;     
  		
}



/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */

