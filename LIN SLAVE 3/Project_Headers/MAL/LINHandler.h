/*
 * LINHandler.h
 *
 *  Created on: Dec 7, 2015
 *      Author: PUG
 */
/*============================================================================*/
/*                         			AEP 	                                  */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*
 * Source: LINHandler.h
 * Revision: 1.0
 * Authors: Benjamin Aguilar.
 * Date: December 06, 2015
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/* LIN state machine
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Automotive Entry Program                                 */
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
#ifndef LINHANDLER_H_
#define LINHANDLER_H_


/* Includes */
/*============================================================================*/
#include "HAL/MPC5606B.h"
#include "HAL/type_definitions.h"
#include "Application/Application.h"
#include "HAL/LINFlex.h"


/*============================================================================*/

/* Constants and types */
/*============================================================================*/

typedef enum
{
	TX_INTERRUPT,
	RX_INTERRUPT
}E_INTERRUPT_EVNT;

typedef enum
{
	IDLE,
	TX_ID,
	RX_ID
}E_LIN_STATES;

#define MASTER_CMD_ALL 		0x0F   		/* ID: CF */ 
#define MASTER_CMD_SLV3 	0x12  		/* ID: 92 */
#define SLAVE3_RSP 			0x22       	/* ID: E2 */
#define SLAVE3_ID 			0x32        /* ID: 32 */

/*Get data bytes of the buffer*/
#define GETBYTE_ID			((T_UBYTE)(LINFLEX_0.BIDR.B.ID))
#define GETBYTE_DATA0		((T_UBYTE)(LINFLEX_0.BDRL.B.DATA0))

/*Put data bytes on the buffer*/
#define PUTBYTE_DATA0		(LINFLEX_0.BDRL.B.DATA0)
#define PUTBYTE_DATA1		(LINFLEX_0.BDRL.B.DATA1)
#define PUTBYTE_DATA2		(LINFLEX_0.BDRL.B.DATA2)
#define PUTBYTE_DATA3		(LINFLEX_0.BDRL.B.DATA3)
#define PUTBYTE_DATA4		(LINFLEX_0.BDRM.B.DATA4)
#define PUTBYTE_DATA5		(LINFLEX_0.BDRM.B.DATA5)
#define PUTBYTE_DATA6		(LINFLEX_0.BDRM.B.DATA6)
#define RESTART_LIN_STMCH	(LINFLEX_0.LINCR2.B.DDRQ = 1)
/*============================================================================*/

/* Exported Variables */
/*============================================================================*/

/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
void LIN_Slv_StateMachine(E_INTERRUPT_EVNT le_event);
/*============================================================================*/

#endif /* LINHANDLER_H_ */






