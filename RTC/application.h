/* 
 * File:   application.h
 * Author: Abdelrahim Bebo
 *
 * Created on February 22, 2024, 12:07 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/*Section : MACRO DECLARATIONS*/
#define _XTAL_FREQ 8000000
typedef unsigned char   uint8_t;


/*Section : INCLUDES*/
#include "ECU_layer/sev_seg/ecu_sev_seg.h"
#include "Mcal_layer/interrupt/mcal_external_interrupt.h"
#include "ECU_layer/LCD/ecu_lcd.h"
#include "ECU_layer/keypad/ecu_key_pad.h"
#include "Mcal_layer/TIMER0/hal_timer0.h"
/*Section : MACRO FUNCTIONS DECLARATIONS*/

/*Section : DATATYPES DECLARATIONS*/
lcd_4bit_t lcd_1 ={
    .lcd_rs.port=PORTC_INDEX,
    .lcd_rs.pin=PIN0,
    .lcd_rs.direction=OUTPUT,
    .lcd_rs.logic=LOW,
    .lcd_en.port=PORTC_INDEX,
    .lcd_en.pin=PIN1,
    .lcd_en.direction=OUTPUT,
    .lcd_en.logic=LOW,
    .lcd_data[0].port=PORTC_INDEX,
    .lcd_data[0].pin=PIN2,
    .lcd_data[0].direction=OUTPUT,
    .lcd_data[0].logic=LOW,
    .lcd_data[1].port=PORTC_INDEX,
    .lcd_data[1].pin=PIN3,
    .lcd_data[1].direction=OUTPUT,
    .lcd_data[1].logic=LOW,
    .lcd_data[2].port=PORTC_INDEX,
    .lcd_data[2].pin=PIN4,
    .lcd_data[2].direction=OUTPUT,
    .lcd_data[2].logic=LOW,
    .lcd_data[3].port=PORTC_INDEX,
    .lcd_data[3].pin=PIN5,
    .lcd_data[3].direction=OUTPUT,
    .lcd_data[3].logic=LOW
};


/*Section : FUNCTIONS DECLARATIONS*/
void application_initialize (void);

#endif	/* APPLICATION_H */