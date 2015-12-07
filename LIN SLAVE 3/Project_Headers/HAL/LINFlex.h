/*
 * LINFlex.h
 *
 *  Created on: Dec 6, 2015
 *      Author: PUG
 */
/*============================================================================*/
/*                         			AEP 	                                  */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*
 * Source: LINflex.h
 * Revision: 1.0
 * Authors: Jorge Gomez.
 * Date: December 02, 2015
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/* header - LINFLEX Initialization, configuration and ISR
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
/*
 * $Log: LED.c $
  ============================================================================*/
#ifndef LINFLEX_H_
#define LINFLEX_H_


/* Includes */
/*============================================================================*/
#include "HAL/MPC5606B.h"
#include "HAL/type_definitions.h"
#include "Signaltypes.h"
#include "HAL\IntcInterrupts.h"
#include "MAL/LINHandler.h"

/*============================================================================*/

/* Constants and types */
/*============================================================================*/



/*============================================================================*/

/* Exported Variables */
/*============================================================================*/
/*============================================================================*/
 

/* Exported functions prototypes */
/*============================================================================*/
 void init_LINflex_Slv(void);

/*============================================================================*/

#endif /* LINFLEX_H_ */






