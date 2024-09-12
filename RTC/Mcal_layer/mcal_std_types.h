/* 
 * File:   mcal_std_types.h
 * Author: hp
 *
 * Created on February 21, 2024, 11:56 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H


/*Section : INCLUDES*/
#include "std_libiraries.h"
#include "compiler.h"






/*Section : DATATYPES DECLARATIONS*/

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;

typedef uint8 std_returntype;


/*Section : MACRO DECLARATIONS*/

#define STD_HIGH        0X01
#define STD_LOW         0X00

#define STD_ON          0X01
#define STD_OFF         0X00

#define STD_ACTIVE      0X01
#define STD_IDLE        0X00

#define E_OK          (std_returntype)0x01
#define E_NOT_OK      (std_returntype)0x00

#define ZERO_INIT 0 


/*Section : MACRO FUNCTIONS DECLARATIONS*/

/*Section : FUNCTIONS DECLARATIONS*/

#endif	/* MCAL_STD_TYPES_H */

