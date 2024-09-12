/* 
 * File:   ecu_sev_seg.h
 * Author: hp
 *
 * Created on June 26, 2024, 12:40 AM
 */

#ifndef ECU_SEV_SEG_H
#define	ECU_SEV_SEG_H


/*Section : MACRO DECLARATIONS*/
#define SEGMENT_PIN0 0
#define SEGMENT_PIN1 1
#define SEGMENT_PIN2 2
#define SEGMENT_PIN3 3

/*Section : INCLUDES*/
#include "ecu_sev_seg_cfg.h"
#include "../../Mcal_layer/GPIO/hal_gpio.h"

/*Section : MACRO FUNCTIONS DECLARATIONS*/

/*Section : DATATYPES DECLARATIONS*/

typedef enum{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;

typedef struct{
        pin_config_t segment_pins[4];
        segment_type_t segment_type;
}segment_t;

/*Section : FUNCTIONS DECLARATIONS*/

std_returntype sev_seg_initialize(const segment_t *seg);
std_returntype sev_seg_write_number(const segment_t *seg , uint8 number);

#endif	/* ECU_SEV_SEG_H */

