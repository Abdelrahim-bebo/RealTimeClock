/* 
 * File:   mcal_interrupt_config.h
 * Author: hp
 *
 * Created on July 1, 2024, 8:05 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/*Section : INCLUDES*/
#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "mcal_interrupt_gen_cfg.h"
#include "../../Mcal_layer/GPIO/hal_gpio.h"

/*Section : MACRO DECLARATIONS*/

#define INTERRUPT_ENABLE    1
#define INTERRUPT_DISABLE   0
#define INTERRUPT_OCUUR     1
#define INTERRUPT_NOT_OCCUR 0
#define INTERRUPT_PRIORITY_ENABLE  1
#define INTERRUPT_PRIORITY_DISABLE 0

/*Section : MACRO FUNCTIONS DECLARATIONS*/
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
/*this macro will enable priority levels on interrupt*/
#define INTERRUPT_PriorityLevelEnable()        (RCONbits.IPEN = 1)
/*this macro will disable priority levels on interrupt*/
#define INTERRUPT_PriorityLevelDisable()       (RCONbits.IPEN = 0)
/*this macro will enable high priority glopal interrupt*/
#define INTERRUPT_GlopalInterruptHighEnable()  (INTCONbits.GIEH = 1)
/*this macro will disable high priority glopal interrupt*/
#define INTERRUPT_GlopalInterruptHighDisable() (INTCONbits.GIEH = 0)
/*this macro will enable low priority glopal interrupt*/
#define INTERRUPT_GlopalInterruptLowEnable()   (INTCONbits.GIEL = 1)
/*this macro will disable low priority glopal interrupt*/
#define INTERRUPT_GlopalInterruptLowDisable()  (INTCONbits.GIEL = 0)
#else
/*this macro will enable glopal interrupt*/
#define INTERRUPT_GlopalInterruptEnable()   (INTCONbits.GIE = 1)
/*this macro will disable glopal interrupt*/
#define INTERRUPT_GlopalInterruptDisable()   (INTCONbits.GIE = 0)
/*this macro will enable Periphral interrupt*/
#define INTERRUPT_PeriphralInterruptEnable()   (INTCONbits.PEIE = 1)
/*this macro will disable Periphral interrupt*/
#define INTERRUPT_PeriphralInterruptDisable()  (INTCONbits.PEIE = 0)
#endif

/*Section : DATATYPES DECLARATIONS*/
typedef enum{
    INTERRUPT_LOW_PRIORITY = 0,
    INTERRUPT_High_PRIORITY        
    }interrupt_priority_cfg;

/*Section : FUNCTIONS DECLARATIONS*/

#endif	/* MCAL_INTERRUPT_CONFIG_H */

