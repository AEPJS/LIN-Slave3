/*
 * Application.h
 *
 *  Created on: Dec 7, 2015
 *      Author: PUG
 */
/*============================================================================*/
/*                                  AEP		                                  */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Application.h $
 * $Revision:  1.0$
 * $Author: Benjamin Aguilar$
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
 * $Log: Application.h $
  ============================================================================*/
#ifndef APPLICATION_H_
#define APPLICATION_H_


/* Includes */
/*============================================================================*/
#include "HAL/type_definitions.h"
#include "HAL/PLL.h"
#include "HAL/LINFlex.h"
#include "Signaltypes.h"
#include "HAL/GPIO.h"
#include "HAL/PIT.h"
#include "MAL/LINHandler.h"
#include "MAL/LED.h"
/* Constants and types */
/*============================================================================*/


/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
 void Slave_Actions (void);
 void LED_StateMachine(T_CMDTYPE le_slvcmd);


#endif /* APPLICATION_H_ */ /* Notice: the file ends with a blank new line to avoid compiler warnings */





