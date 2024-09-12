/* 
 * File:   ecu_key_pad.h
 * Author: hp
 *
 * Created on June 27, 2024, 1:28 PM
 */

#ifndef ECU_KEY_PAD_H
#define	ECU_KEY_PAD_H


/*Section : MACRO DECLARATIONS*/
#define ECU_KEYPAD_ROW 4
#define ECU_KEYPAD_COLUMN 4

/*Section : INCLUDES*/
#include "ecu_key_pad_cfg.h"
#include "../../Mcal_layer/GPIO/hal_gpio.h"

/*Section : MACRO FUNCTIONS DECLARATIONS*/


/*Section : DATATYPES DECLARATIONS*/
typedef struct{
    pin_config_t keypad_row_pins [ECU_KEYPAD_ROW];
    pin_config_t keypad_column_pins [ECU_KEYPAD_COLUMN];
}keypad_t;

/*Section : FUNCTIONS DECLARATIONS*/
std_returntype keypad_initialize(const keypad_t *_keypad_obj);
std_returntype keypad_get_value(const keypad_t *_keypad_obj , uint8 * value);


#endif	/* ECU_KEY_PAD_H */

