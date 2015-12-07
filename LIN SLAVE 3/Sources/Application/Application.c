/*
 * Application.c
 *
 *  Created on: Dec 7, 2015
 *      Author: PUG
 */
/*============================================================================*/
/*                       			AEP		                                  */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Application.c $
 * $Revision:  1.0$
 * $Author: Benjamin Aguilar $
 * $Date: 07/12/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** 
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
 * $Log: Application.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "Application/Application.h"


/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/
T_SLV_STAT re_SlaveStatus = ENABLED;
T_LEDSTAT re_LEDStatus = L_ON;
extern T_UBYTE		rub_Rx_ID;			/*Variable for Received ID      */
 extern T_CMDTYPE	re_SlvCmd;	/*Variable for Received Command */

/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/
/**************************************************************
*  Name                 :  Slave_Actions
*  Description          :  Change the Status of the slave and the LED called every 50ms
*  Parameters           :  void
*  Return               :  void
*  Precondition         :  The periodic task is called
*  Postcondition        :  The slave change its status
**************************************************************/
void Slave_Actions(void)
{
	if(re_SlvCmd != cmd_NONE)
	{
		if(re_SlaveStatus == ENABLED)
		{
			if (re_SlvCmd == cmd_disable_slv)
			{
				re_SlaveStatus = DISABLED;
			}
			else
			{
				LED_StateMachine(re_SlvCmd);
			}
		}
		else if(re_SlaveStatus == DISABLED)
		{
			if(re_SlvCmd == cmd_enable_slv)
			{
				re_SlaveStatus = ENABLED;
			}
			else{}
		}
		else{}
	}
	else{}

}
/**************************************************************
*  Name                 :  LED_StateMachine
*  Description          :  State machine of the behavior of the LED, executed every 50ms
*  Parameters           :  T_CMDTYPE
*  Return               :  void
*  Precondition         :  The periodic task is called
*  Postcondition        :  Switch the status of the LED
**************************************************************/
void LED_StateMachine(T_CMDTYPE le_slvcmd)
{
	switch(re_LEDStatus)
	{
		case L_OFF:
			    LED_OFF(LED1);
				re_LEDStatus = L_OFF;

				if(le_slvcmd == cmd_LED_toggling)
				{
					TOGGLE_LED();
					re_LEDStatus = TOGGLING;
				}
				else if(le_slvcmd == cmd_LED_on)
				{
					LED_ON(LED1);
					re_LEDStatus = L_ON;
				}
				else{/*Do nothing*/}
			break;
			
		case TOGGLING:
			TOGGLE_LED();
				re_LEDStatus = TOGGLING;
				if(le_slvcmd == cmd_LED_off)
				{
					LED_OFF(LED1);
					re_LEDStatus = L_OFF;
				}
				else if(le_slvcmd == cmd_LED_on)
				{
					LED_ON(LED1);
					re_LEDStatus = L_ON;
				}
				else{/*Do nothing*/}
			break;
			
		case L_ON:
			    LED_ON(LED1);
				re_LEDStatus = L_ON;	
				if(le_slvcmd == cmd_LED_off)
				{
					LED_OFF(LED1);
					re_LEDStatus = L_OFF;
				}
				else if(le_slvcmd == cmd_LED_toggling)
				{
					TOGGLE_LED();
					re_LEDStatus = TOGGLING;
				}
				else{/*Do nothing*/}
			break;
			
		default:
				re_LEDStatus = L_ON;
			break;
	}
}


