/*
 * Signaltypes.h
 *
 *  Created on: Dec 7, 2015
 *      Author: PUG
 */

#ifndef SIGNALTYPES_H_
#define SIGNALTYPES_H_


typedef enum
{
	cmd_NONE,
	cmd_LED_on,
	cmd_LED_off,
	cmd_LED_toggling,
	cmd_disable_slv,
	cmd_enable_slv
}T_CMDTYPE;

typedef T_UBYTE T_SCALAR;

typedef struct{
	T_UBYTE e[6];
} T_ARRAY;

typedef enum
{
	L_OFF,
	L_ON,
	TOGGLING
}T_LEDSTAT;


typedef enum
{
	DISABLED,
	ENABLED
}T_SLV_STAT;


#endif /* SIGNALTYPES_H_ */
