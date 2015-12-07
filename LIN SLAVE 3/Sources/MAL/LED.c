/*
 * LED.c
 *
 *  Created on: Nov 20, 2015
 *      Author: PUG
 */
/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: LED.h $
 * $Revision: A $
 * $Author: Benjamin Aguilar $
 * $Date: December 06, 2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** Turn on the LED bar to indicate the initializacion of the window as closed 
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
 * $Log: LED.c $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "MAL/LED.h"


/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/
T_UBYTE ruw_wait = 1;


/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/


void ON_LED(void)
{
	LED_ON(LED1);
}

void OFF_LED(void)
{
	LED_OFF(LED1);
}

void TOGGLE_LED(void)
{
	if(ruw_wait == 10)
	{
	LED_TOGGLE(LED1);
	ruw_wait=0;
	}
	ruw_wait++;
}

/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */

