/* 
 * File:   application.c
 * Author: Abdelrahim Bebo
 *
 * Created on February 22, 2024, 12:07 AM
 */

#include "application.h"

uint8 lcd1_counter = ZERO_INIT;
uint8 sec=0,min=0,hour=0;
uint8 keypad_Value = 0;
uint8 digit_one = 0;
uint8 digit_two= 0;

void Interrupt_handler(void){
    sec+=1;
  }


timer0_t timer_0 = {
    .TMR0_InterruptHandler = Interrupt_handler,
    .prescaler_enable = TIMER0_PRESCALER_ENABLE_CFG,
    .prescaler_value = TIMER0_PRESCALER_DIV_BY_32,
    .timer0_mode = TIMER0_TIMER_MODE,
    .timer0_preload_value = 3036,
    .timer0_register_size = TIMER0_16BIT_REGISTER_MODE
};

segment_t seg_1 = {
   .segment_pins[0].port = PORTA_INDEX,
   .segment_pins[0].pin = PIN0,
   .segment_pins[0].direction = OUTPUT,
   .segment_pins[0].logic = LOW,
   .segment_pins[1].port = PORTA_INDEX,
   .segment_pins[1].pin = PIN1,
   .segment_pins[1].direction = OUTPUT,
   .segment_pins[1].logic = LOW,
   .segment_pins[2].port = PORTA_INDEX,
   .segment_pins[2].pin = PIN2,
   .segment_pins[2].direction = OUTPUT,
   .segment_pins[2].logic = LOW,
   .segment_pins[3].port = PORTA_INDEX,
   .segment_pins[3].pin = PIN3,
   .segment_pins[3].direction = OUTPUT,
   .segment_pins[3].logic = LOW,
   .segment_type = SEGMENT_COMMON_ANODE
};

keypad_t key_pad = {
    .keypad_column_pins[0].port = PORTD_INDEX,
    .keypad_column_pins[0].pin = PIN4,
    .keypad_column_pins[0].direction = INPUT,
    .keypad_column_pins[0].logic = LOW,
    
    .keypad_column_pins[1].port = PORTD_INDEX,
    .keypad_column_pins[1].pin = PIN5,
    .keypad_column_pins[1].direction = INPUT,
    .keypad_column_pins[1].logic = LOW,
    
    .keypad_column_pins[2].port = PORTD_INDEX,
    .keypad_column_pins[2].pin = PIN6,
    .keypad_column_pins[2].direction = INPUT,
    .keypad_column_pins[2].logic = LOW,
    
    .keypad_column_pins[3].port = PORTD_INDEX,
    .keypad_column_pins[3].pin = PIN7,
    .keypad_column_pins[3].direction = INPUT,
    .keypad_column_pins[3].logic = LOW,
    
    .keypad_row_pins[0].port = PORTD_INDEX,
    .keypad_row_pins[0].pin = PIN0,
    .keypad_row_pins[0].direction = OUTPUT,
    .keypad_row_pins[0].logic = LOW,
    
    .keypad_row_pins[1].port = PORTD_INDEX,
    .keypad_row_pins[1].pin = PIN1,
    .keypad_row_pins[1].direction = OUTPUT,
    .keypad_row_pins[1].logic = LOW,
    
    .keypad_row_pins[2].port = PORTD_INDEX,
    .keypad_row_pins[2].pin = PIN2,
    .keypad_row_pins[2].direction = OUTPUT,
    .keypad_row_pins[2].logic = LOW,
    
    .keypad_row_pins[3].port = PORTD_INDEX,
    .keypad_row_pins[3].pin = PIN3,
    .keypad_row_pins[3].direction = OUTPUT,
    .keypad_row_pins[3].logic = LOW
};

int main() { 
    std_returntype ret = E_NOT_OK;
       application_initialize();
       ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Press 1 to set clock");
    while(1){
        do{
        ret = keypad_get_value(&key_pad,&keypad_Value);
        ret = gpio_port_write_logic(PORTB_INDEX , 0x01);
        ret = gpio_port_write_logic(PORTA_INDEX,(uint8)(hour/10));
        __delay_ms(5);
        
        ret = gpio_port_write_logic(PORTB_INDEX , 0x02);
        ret = gpio_port_write_logic(PORTA_INDEX, (uint8)(hour%10));
        __delay_ms(5);
        
        ret = gpio_port_write_logic(PORTB_INDEX , 0x04);
        ret = gpio_port_write_logic(PORTA_INDEX, (uint8)(min/10));
        __delay_ms(5);
        
        ret = gpio_port_write_logic(PORTB_INDEX , 0x08);
        ret = gpio_port_write_logic(PORTA_INDEX,(uint8)(min%10));
        __delay_ms(5);
        
        ret = gpio_port_write_logic(PORTB_INDEX , 0x10);
        ret = gpio_port_write_logic(PORTA_INDEX,(uint8)(sec/10));
        __delay_ms(5);
        
        ret = gpio_port_write_logic(PORTB_INDEX , 0x20);
        ret = gpio_port_write_logic(PORTA_INDEX,(uint8)(sec%10));
        __delay_ms(5);
        
        if(sec == 60){
            sec=0;
            min++;
        }
        else{/*Nothing*/}
        if(min == 60){
            min=0;
            hour++;
        }
        else{/*Nothing*/}
        if(hour == 24){
            hour=0;
        }
        else{/*Nothing*/}
        }while(keypad_Value == 0);
        if(keypad_Value == '1'){
            __delay_ms(250);
            ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"Hours:--");
            do{
                ret = keypad_get_value(&key_pad,&digit_one);
            }while(digit_one == 0);
            __delay_ms(250);
            ret = lcd_4bit_send_char_data_pos(&lcd_1,2,7,digit_one);
            __delay_ms(250);
            do{
                ret = keypad_get_value(&key_pad,&digit_two);
            }while(digit_two == 0);
            __delay_ms(300);
            ret = lcd_4bit_send_char_data_pos(&lcd_1,2,8,digit_two);
            __delay_ms(300);
            hour = (digit_one-48)*10+(digit_two-48);
            digit_one = 0;
            digit_two = 0;
            ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"Minutes:--");
            do{
                ret = keypad_get_value(&key_pad,&digit_one);
            }while(digit_one == 0);
            __delay_ms(250);
            ret = lcd_4bit_send_char_data_pos(&lcd_1,3,9,digit_one);
            __delay_ms(250);
            do{
                ret = keypad_get_value(&key_pad,&digit_two);
            }while(digit_two == 0);
            __delay_ms(300);
            ret = lcd_4bit_send_char_data_pos(&lcd_1,3,10,digit_two);
            __delay_ms(300);
            min = (digit_one-48)*10+(digit_two-48);
            digit_one = 0;
            digit_two = 0;
            ret = lcd_4bit_send_string_pos(&lcd_1,4,1,"Seconds:--");
            do{
                ret = keypad_get_value(&key_pad,&digit_one);
            }while(digit_one == 0);
            __delay_ms(250);
            ret = lcd_4bit_send_char_data_pos(&lcd_1,4,9,digit_one);
            __delay_ms(250);
            do{
                ret = keypad_get_value(&key_pad,&digit_two);
            }while(digit_two == 0);
            __delay_ms(300);
            ret = lcd_4bit_send_char_data_pos(&lcd_1,4,10,digit_two);
            __delay_ms(300);
            sec = (digit_one-48)*10+(digit_two-48);
            digit_one = 0;
            digit_two = 0;
            keypad_Value = 0;
            lcd_4bit_send_command(&lcd_1,_LCD_CLEAR);
            __delay_ms(300);
            ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Press 1 to set clock");
        }
        else{
            lcd_4bit_send_command(&lcd_1,_LCD_CLEAR);
            __delay_ms(300);
            ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Wrong choice");
            __delay_ms(300);
            lcd_4bit_send_command(&lcd_1,_LCD_CLEAR);
            __delay_ms(300);
            ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Press 1 to set clock");
            keypad_Value = 0;
        }


    }
    return (EXIT_SUCCESS);
}

  void application_initialize(void){
    std_returntype ret = E_NOT_OK;
    ret = Timer0_Init(&timer_0);
    ret = lcd_4bit_initialize(&lcd_1);
    ret = keypad_initialize(&key_pad);
    ret = sev_seg_initialize(&seg_1);
    ret = gpio_port_direction_initialize(PORTB_INDEX , OUTPUT);
}


