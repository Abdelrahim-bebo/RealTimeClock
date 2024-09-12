/* 
 * File:   hal_gpio.h
 * Author: hp
 *
 * Created on February 21, 2024, 11:10 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H
/*Section : INCLUDES*/
#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "hal_gpio_cfg.h"

/*Section : MACRO DECLARATIONS*/

#define BIT_MASK      (uint8)1
#define PORT_PIN_MAX_NUM 8
#define PORT_MAX_NUM 5
#define PORT_PIN_CONFIGURATIONS  CONFIG_ENABLE
#define GPIO_PORT_CONFIGURATIONS  CONFIG_ENABLE
#define PORTC_MASK  0xFF

/*Section : MACRO FUNCTIONS DECLARATIONS*/

#define HWREG8(_x)  (*((volatile uint8 *)(_x)))

#define SET_BIT(REG,BIT_POS)      (REG|=(BIT_MASK<<BIT_POS))
#define CLEAR_BIT(REG,BIT_POS)     (REG&=~(BIT_MASK<<BIT_POS))
#define TOGGLE_BIT(REG,BIT_POS)     (REG^=(BIT_MASK<<BIT_POS))
#define READ_BIT(REG,BIT_POS)     ((REG >> BIT_POS) & BIT_MASK)



/*Section : DATATYPES DECLARATIONS*/

typedef enum{
    LOW,
    HIGH
}logic_t;

typedef enum{
    OUTPUT,
    INPUT
}direction_t;
typedef enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;

typedef enum{
   PORTA_INDEX,
   PORTB_INDEX,
   PORTC_INDEX,
   PORTD_INDEX,
   PORTE_INDEX,
}port_index_t;

typedef struct{
    uint8 port : 3;     /* @ref port_index_t */
    uint8 pin : 3;      /* @ref pin_index_t */
    uint8 logic : 1;    /* @ref logic_t */
    uint8 direction : 1;/* @ref direction_t */
}pin_config_t;

/*Section : FUNCTIONS DECLARATIONS*/

std_returntype gpio_pin_direction_initialize(const pin_config_t * _pin_config);
std_returntype gpio_pin__initialize(const pin_config_t * _pin_config);
std_returntype gpio_pin_get_direction_status(const pin_config_t * _pin_config ,direction_t* dic_status);
std_returntype gpio_pin_write_logic(const pin_config_t * _pin_config , logic_t logic);
std_returntype gpio_pin_read_logic(const pin_config_t * _pin_config , logic_t *logic);
std_returntype gpio_pin_toggle_logic(const pin_config_t * _pin_config);

std_returntype gpio_port_direction_initialize(port_index_t  port ,uint8 direction);
std_returntype gpio_port_get_direction_status(port_index_t  port ,uint8 *dic_status);
std_returntype gpio_port_write_logic(port_index_t  port , uint8 logic);
std_returntype gpio_port_read_logic(port_index_t  port , uint8 *logic);
std_returntype gpio_port_toggle_logic(port_index_t port);


#endif	/* HAL_GPIO_H */

