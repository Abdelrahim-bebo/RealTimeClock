
#include "hal_gpio.h"

volatile uint8 *tris_reg[] = {&TRISA ,&TRISB ,&TRISC ,&TRISD ,&TRISE};
volatile uint8 *lat_reg[] = {&LATA ,&LATB  ,&LATC  ,&LATD  ,&LATE };
volatile uint8 *port_reg[] = {&PORTA ,&PORTB ,&PORTC ,&PORTD ,&PORTE};


/**
 * 
 * @param _pin_config
 * @return 
 */
#if PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
std_returntype gpio_pin_direction_initialize(const pin_config_t * _pin_config){
    std_returntype ret = E_OK;
    if(NULL == _pin_config || _pin_config->pin > PORT_PIN_MAX_NUM-1){
        ret = E_NOT_OK;
    }
    else{
        switch(_pin_config->direction){
            case OUTPUT :{
                CLEAR_BIT(*tris_reg[_pin_config->port],_pin_config->pin);
                break;
            }
            case INPUT :{
                SET_BIT(*tris_reg[_pin_config->port],_pin_config->pin);
                break;
            }
            default :{
                ret = E_NOT_OK;
            }
    }
    }
    return ret;
}
#endif
/**
  * 
  * @param _pin_config
  * @param dic_status
  * @return 
  */
#if PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
std_returntype gpio_pin_get_direction_status(const pin_config_t * _pin_config ,direction_t * dic_status){
    std_returntype ret = E_OK;
    if((NULL == _pin_config) || NULL == (dic_status) || _pin_config->pin > PORT_PIN_MAX_NUM-1){
        ret = E_NOT_OK;
    }
    else{
        *dic_status = READ_BIT(*tris_reg[_pin_config->port],_pin_config->pin);
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @param logic
 * @return 
 */
#if PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
std_returntype gpio_pin_write_logic(const pin_config_t * _pin_config , logic_t logic){
    std_returntype ret = E_OK;
    if((NULL==_pin_config) ||(_pin_config->pin > PORT_PIN_MAX_NUM-1))
    {
        ret = E_NOT_OK ;
    }
        else{
            switch(logic){
            case LOW :
                CLEAR_BIT(*lat_reg[_pin_config->port] , _pin_config->pin);   
                break;
            case HIGH :
                SET_BIT(*lat_reg[_pin_config->port] , _pin_config->pin);
                break;
            default : ret = E_NOT_OK ;
            }}


    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @param logic
 * @return 
 */
#if PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
std_returntype gpio_pin_read_logic(const pin_config_t * _pin_config , logic_t *logic){
    std_returntype ret = E_OK;
    if(NULL==_pin_config || NULL == logic ||_pin_config->pin > PORT_PIN_MAX_NUM-1)
    {
        ret = E_NOT_OK ;
    }
        else{
            *logic = READ_BIT(*port_reg[_pin_config->port] , _pin_config->pin);
        }

    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @return 
 */
#if PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE
std_returntype gpio_pin_toggle_logic(const pin_config_t * _pin_config){
    std_returntype ret = E_OK;
      if(NULL==_pin_config ||_pin_config->pin > PORT_PIN_MAX_NUM-1)
    {
        ret = E_NOT_OK ;
    }
        else{
            TOGGLE_BIT(*lat_reg[_pin_config->port] , _pin_config->pin);
        }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param direction
 * @return 
 */
#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
std_returntype gpio_port_direction_initialize(port_index_t  port ,uint8 direction){
    std_returntype ret = E_OK;
      if( port > PORT_MAX_NUM-1)
    {
        ret = E_NOT_OK ;
    }
      else{
           *tris_reg[port] = direction  ;
        }


    return ret;
}
#endif
/**
  * 
  * @param port
  * @param dic_status
  * @return 
  */
#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
std_returntype gpio_port_get_direction_status(port_index_t port ,uint8 *dic_status){
    std_returntype ret = E_OK;
     if((NULL==dic_status)&&(port > PORT_MAX_NUM-1))
    {
        ret = E_NOT_OK ;
    }
        else{
            *dic_status = *tris_reg[port];
        }

    

    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return 
 */
#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
std_returntype gpio_port_write_logic(port_index_t  port , uint8 logic){
    std_returntype ret = E_OK;
       if( port > PORT_MAX_NUM-1)
    {
        ret = E_NOT_OK ;
    }
      else{
           *lat_reg[port] = logic;
        }


    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return 
 */
#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
std_returntype gpio_port_read_logic(port_index_t  port , uint8 *logic){
    std_returntype ret = E_OK;
     if((NULL==logic) &&(port > PORT_MAX_NUM-1))
    {
        ret = E_NOT_OK ;
    }
        else{
            *logic = *lat_reg[port];
        }

    return ret;
}
#endif
/**
 * 
 * @param port
 * @return 
 */
#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
std_returntype gpio_port_toggle_logic(port_index_t port){
    std_returntype ret = E_OK;
     if( port > PORT_MAX_NUM-1)
    {
        ret = E_NOT_OK ;
    }
      else{
           *lat_reg[port] ^= PORTC_MASK;
        }

    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @return 
 */
#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
std_returntype gpio_pin__initialize(const pin_config_t * _pin_config){
    std_returntype ret = E_OK;
    if((NULL == _pin_config) || _pin_config->pin > PORT_PIN_MAX_NUM-1){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_initialize(_pin_config);
        ret = gpio_pin_write_logic(_pin_config,_pin_config->logic);
    }
    return ret;
}
#endif
