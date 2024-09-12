/* 
 * File:   ecu_sev_seg.c
 * Author: hp
 *
 * Created on June 26, 2024, 12:40 AM
 */
#include "ecu_sev_seg.h"

std_returntype sev_seg_initialize(const segment_t *seg){
     std_returntype ret = E_OK;
       if(NULL==seg){
           ret = E_NOT_OK ;
       } 
       else
        {
           ret = gpio_pin__initialize(&(seg->segment_pins[SEGMENT_PIN0]));
           ret = gpio_pin__initialize(&(seg->segment_pins[SEGMENT_PIN1]));
           ret = gpio_pin__initialize(&(seg->segment_pins[SEGMENT_PIN2]));
           ret = gpio_pin__initialize(&(seg->segment_pins[SEGMENT_PIN3]));
       }
     return ret;
}
std_returntype sev_seg_write_number(const segment_t *seg , uint8 number){
     std_returntype ret = E_OK;
      if(NULL==seg &&  number > 9){
           ret = E_NOT_OK ;
       } 
       else
        {
           ret = gpio_pin_write_logic(&(seg->segment_pins[SEGMENT_PIN0]) , number && 0x01);
           ret = gpio_pin_write_logic(&(seg->segment_pins[SEGMENT_PIN1]) , (number>>1) && 0x01);
           ret = gpio_pin_write_logic(&(seg->segment_pins[SEGMENT_PIN2]) , (number>>2) && 0x01);
           ret = gpio_pin_write_logic(&(seg->segment_pins[SEGMENT_PIN3]) , (number>>3) && 0x01);
       }
     return ret;
}

