/* 
 * File:   ecu_key_pad.c
 * Author: hp
 *
 * Created on June 27, 2024, 1:28 PM
 */

#include "ecu_key_pad.h"

#define _XTAL_FREQ 8000000

static const uint8 btn_values[ECU_KEYPAD_ROW][ECU_KEYPAD_COLUMN]={
                                                    {'7','8','9','/'},
                                                    {'4','5','6','*'},
                                                    {'1','2','3','-'},
                                                    {'#','0','=','+'}
                                                    
};

std_returntype keypad_initialize(const keypad_t *_keypad_obj){
    std_returntype ret = E_OK;
    uint8 rows_counter = ZERO_INIT, columns_counter = ZERO_INIT;
       if(NULL==_keypad_obj){
           ret = E_NOT_OK ;
       } 
       else
        {
           for(rows_counter = ZERO_INIT ;rows_counter<ECU_KEYPAD_ROW;rows_counter++){
               ret = gpio_pin__initialize(&(_keypad_obj->keypad_row_pins[rows_counter]));
           }
            for(columns_counter = ZERO_INIT;columns_counter<ECU_KEYPAD_COLUMN;columns_counter++){
               ret = gpio_pin_direction_initialize(&(_keypad_obj->keypad_column_pins[columns_counter]));
           }
       }
    return ret;
}

std_returntype keypad_get_value(const keypad_t *_keypad_obj , uint8 * value){
     std_returntype ret = E_OK;
     uint8 l_rows_counter = ZERO_INIT, l_columns_counter = ZERO_INIT , l_counter = ZERO_INIT;
     uint8 column_logic = ZERO_INIT;
       if((NULL==_keypad_obj) || (NULL== value) ){
           ret = E_NOT_OK ;
       } 
       else
        {
           for(l_rows_counter = ZERO_INIT ;l_rows_counter<ECU_KEYPAD_ROW;l_rows_counter++){
               for(l_counter = ZERO_INIT ;l_counter<ECU_KEYPAD_ROW;l_counter++){
                   gpio_pin_write_logic(&(_keypad_obj->keypad_row_pins[l_counter]), LOW);
               }
               gpio_pin_write_logic(&(_keypad_obj->keypad_row_pins[l_rows_counter]), HIGH);
               for(l_columns_counter = ZERO_INIT ;l_columns_counter<ECU_KEYPAD_COLUMN;l_columns_counter++){
                   ret = gpio_pin_read_logic(&(_keypad_obj->keypad_column_pins[l_columns_counter]),&column_logic);
                   if(HIGH == column_logic){
                       *value = btn_values[l_rows_counter][l_columns_counter];
                   }
               }
           }
       }
     return ret;
}
