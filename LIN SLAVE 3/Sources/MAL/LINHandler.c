/*
 * LINHandler.c
 *
 *  Created on: Dec 7, 2015
 *      Author: PUG
 */
/*============================================================================*/
/*                        			 AEP 	                                  */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*
 * $Source: LINHandler.c 
 * $Revision: 1.0 
 * Authors: Benjamin Aguilar 
 * $Date: December 06, 2015 
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/* LINFLEX State machine.    
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

/* Includes */
/*============================================================================*/
#include "MAL/LINHandler.h"

/*============================================================================*/

/* Constants and types  */
/*============================================================================*/
const T_SCALAR cub_TeamNumber = 0x07;
const T_ARRAY caub_Names = {'J', 'S', 'R', 'B', 'A', 'O'};


/*============================================================================*/

/* Variables */
/*============================================================================*/
E_LIN_STATES re_SlvState = IDLE;
extern T_SLV_STAT re_SlaveStatus;
extern T_LEDSTAT re_LEDStatus;
extern T_UBYTE		rub_Rx_ID;			/*Variable for Received ID      */
 extern T_CMDTYPE	re_SlvCmd;	/*Variable for Received Command */
/*============================================================================*/

/* Private functions prototypes */
/*============================================================================*/
/*============================================================================*/

/* Inline functions */
/*============================================================================*/
/*============================================================================*/

/* Private functions */
/*============================================================================*/
/*============================================================================*/

/**************************************************************
 *  Name                 :  LIN_Slv_StateMachine
 *  Description          :  State machine for the actualization of the parameters of the slave 3
 *  Parameters           :  void
 *  Return               :  void
 *  Precondition         :  An interrupt must occur.
 *  Postcondition        :  Acquires the data of LIN.
 **************************************************************/
void LIN_Slv_StateMachine(E_INTERRUPT_EVNT le_event) 
{
	switch(re_SlvState)
	{
		case IDLE:
				if(le_event == RX_INTERRUPT)
				{
					rub_Rx_ID = GETBYTE_ID;
					re_SlvState = RX_ID;
				}
				else if(le_event == TX_INTERRUPT)
				{
					rub_Rx_ID = GETBYTE_ID;
					re_SlvState = TX_ID;
				}
				else
				{
					re_SlvState = IDLE; 		
				}
			break;
			
		case RX_ID:
				if((rub_Rx_ID == MASTER_CMD_ALL) || (rub_Rx_ID == MASTER_CMD_SLV3))
				{
					re_SlvCmd = GETBYTE_DATA0 & 0x07;
					re_SlvState = IDLE; 
				}
				else
				{
					re_SlvState = IDLE; 		
				}
			break;
			
		case TX_ID:
				if(rub_Rx_ID == SLAVE3_RSP)
				{
					PUTBYTE_DATA0 = (T_UBYTE)(re_LEDStatus);
					PUTBYTE_DATA1 = (T_UBYTE)(re_SlaveStatus);
					LINFLEX_0.LINCR2.B.DTRQ = 1;
					re_SlvState = IDLE; 
				}
				else if(rub_Rx_ID == SLAVE3_ID)
				{
					PUTBYTE_DATA1 = (T_UBYTE)(caub_Names.e[0]);
					PUTBYTE_DATA2 = (T_UBYTE)(caub_Names.e[1]);
					PUTBYTE_DATA3 = (T_UBYTE)(caub_Names.e[2]);
					PUTBYTE_DATA4 = (T_UBYTE)(caub_Names.e[3]);
					PUTBYTE_DATA5 = (T_UBYTE)(caub_Names.e[4]);
					PUTBYTE_DATA6 = (T_UBYTE)(caub_Names.e[5]);
					PUTBYTE_DATA0 = (T_UBYTE)(cub_TeamNumber);
					LINFLEX_0.LINCR2.B.DTRQ = 1;
					re_SlvState = IDLE; 
				}
				else
				{
					re_SlvState = IDLE;		
				}
			break;
			
		default:
			re_SlvState = IDLE;			
			RESTART_LIN_STMCH;
			break;
	}
}


/* Exported functions */
/*============================================================================*/


/*============================================================================*/

/* Notice: the file ends with a blank new line to avoid compiler warnings */


