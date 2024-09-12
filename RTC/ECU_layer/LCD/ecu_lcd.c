/* 
 * File:   ecu_lcd.c
 * Author: hp
 *
 * Created on June 29, 2024, 11:49 AM
 */

#include "ecu_lcd.h"
static std_returntype lcd_send_4bits(const lcd_4bit_t *lcd, uint8 _data_command);
static std_returntype lcd_4bits_sned_enable_signal(const lcd_4bit_t *lcd);
static std_returntype lcd_8bits_sned_enable_signal(const lcd_8bit_t *lcd);
static std_returntype lcd_8bits_set_cursor(const lcd_8bit_t *lcd , uint8 row , uint8 column);
static std_returntype lcd_4bits_set_cursor(const lcd_4bit_t *lcd , uint8 row , uint8 column);

std_returntype lcd_4bit_initialize(const lcd_4bit_t *lcd){
     std_returntype ret = E_OK;
     uint8 l_data_pins_counter = ZERO_INIT;
       if(NULL==lcd){
           ret = E_NOT_OK ;
       } 
       else
        {
           ret = gpio_pin__initialize(&(lcd->lcd_rs));
           ret = gpio_pin__initialize(&(lcd->lcd_en));
           for (l_data_pins_counter=0;l_data_pins_counter<4;l_data_pins_counter++){
               ret = gpio_pin__initialize(&(lcd->lcd_data[l_data_pins_counter]));
           }
           __delay_ms(20);
           ret = lcd_4bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
           __delay_ms(5);
           ret = lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
           __delay_us(150);
           ret = lcd_4bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
           ret = lcd_4bit_send_command(lcd,_LCD_CLEAR);
           ret = lcd_4bit_send_command(lcd,_LCD_RETURN_HOME);
           ret = lcd_4bit_send_command(lcd,_LCD_ENTRY_MODE);
           ret = lcd_4bit_send_command(lcd,_LCD_CURSOR_OFF_DISPLAY_ON);
           ret = lcd_4bit_send_command(lcd,_LCD_4BIT_MODE_2_LINE);
           ret = lcd_4bit_send_command(lcd,0x80);
           
       }
     return ret;
}
std_returntype lcd_4bit_send_command(const lcd_4bit_t *lcd , uint8 command){
         std_returntype ret = E_OK;
       if(NULL==lcd){
           ret = E_NOT_OK ;
       } 
       else
        {
           ret = gpio_pin_write_logic(&(lcd->lcd_rs),LOW);
           ret = lcd_send_4bits(lcd , command >> 4 );
           lcd_4bits_sned_enable_signal(lcd);
           ret = lcd_send_4bits(lcd , command);
           lcd_4bits_sned_enable_signal(lcd);
       }
     return ret;
}
std_returntype lcd_4bit_send_char_data(const lcd_4bit_t *lcd , uint8 data){
         std_returntype ret = E_OK;
       if(NULL==lcd){
           ret = E_NOT_OK ;
       } 
       else
        {
           ret = gpio_pin_write_logic(&(lcd->lcd_rs),HIGH);
           ret = lcd_send_4bits(lcd , data >> 4 );
           lcd_4bits_sned_enable_signal(lcd);
           ret = lcd_send_4bits(lcd , data);
           lcd_4bits_sned_enable_signal(lcd);
       }
     return ret;
}
std_returntype lcd_4bit_send_char_data_pos(const lcd_4bit_t *lcd , uint8 row, uint8 column, uint8 data){
         std_returntype ret = E_OK;
       if(NULL==lcd){
           ret = E_NOT_OK ;
       } 
       else
        {
           ret = lcd_4bits_set_cursor(lcd, row, column);
           ret = lcd_4bit_send_char_data(lcd, data);
       }
     return ret;
}
std_returntype lcd_4bit_send_string(const lcd_4bit_t *lcd , uint8 *str){
         std_returntype ret = E_OK;
       if(NULL==lcd){
           ret = E_NOT_OK ;
       } 
       else
        {
           while(*str){
               ret = lcd_4bit_send_char_data(lcd , *str++);
           }
       }
     return ret;
}
std_returntype lcd_4bit_send_string_pos(const lcd_4bit_t *lcd , uint8 row, uint8 column, uint8 *str){
         std_returntype ret = E_OK;
       if(NULL==lcd){
           ret = E_NOT_OK ;
       } 
       else
        {
           ret = lcd_4bits_set_cursor(lcd, row, column);
           ret = lcd_4bit_send_string(lcd , str);
       }
     return ret;
}
std_returntype lcd_4bit_send_custome_char(const lcd_4bit_t *lcd , uint8 row, uint8 column,
                                          const uint8 _chr[], uint8 mem_pos){
         std_returntype ret = E_OK;
         uint8 lcd_counter = ZERO_INIT;
       if(NULL==lcd){
           ret = E_NOT_OK ;
       } 
       else
        {
           ret = lcd_4bit_send_command(lcd, (_LCD_CGRAM_START+(mem_pos*9)));
           for(lcd_counter=0; lcd_counter<=7;++lcd_counter){
               ret = lcd_4bit_send_char_data(lcd ,_chr[lcd_counter]);
           }
           ret = lcd_4bit_send_char_data_pos(lcd , row , column , mem_pos);
       }
     return ret;
}

std_returntype lcd_8bit_initialize(const lcd_8bit_t *lcd){
         std_returntype ret = E_OK;
     uint8 l_data_pins_counter = ZERO_INIT;
       if(NULL==lcd){
           ret = E_NOT_OK ;
       } 
       else
        {
           ret = gpio_pin__initialize(&(lcd->lcd_rs));
           ret = gpio_pin__initialize(&(lcd->lcd_en));
           for (l_data_pins_counter=0;l_data_pins_counter<8;l_data_pins_counter++){
               ret = gpio_pin__initialize(&(lcd->lcd_data[l_data_pins_counter]));
           }
           __delay_ms(20);
           ret = lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
           __delay_ms(5);
           ret = lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
           __delay_us(150);
           ret = lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
           ret = lcd_8bit_send_command(lcd,_LCD_CLEAR);
           ret = lcd_8bit_send_command(lcd,_LCD_RETURN_HOME);
           ret = lcd_8bit_send_command(lcd,_LCD_ENTRY_MODE);
           ret = lcd_8bit_send_command(lcd,_LCD_CURSOR_OFF_DISPLAY_ON);
           ret = lcd_8bit_send_command(lcd,_LCD_8BIT_MODE_2_LINE);
           ret = lcd_8bit_send_command(lcd,0x80);
       }
     return ret;
}
std_returntype lcd_8bit_send_command(const lcd_8bit_t *lcd , uint8 command){
         std_returntype ret = E_OK;
    uint8 l_pin_counter = ZERO_INIT;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        /* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
        /* Write Logic (0) to the "Register Select" Pin to select the "Instruction Register"  */
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), LOW);
        /* Send the Command through the (8-Pins" Data lines */
        for(l_pin_counter=0; l_pin_counter<8; ++l_pin_counter){
            ret = gpio_pin_write_logic(&(lcd->lcd_data[l_pin_counter]), (command >> l_pin_counter) & (uint8)0x01);
        }
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_8bits_sned_enable_signal(lcd);
    }
    return ret;
}
std_returntype lcd_8bit_send_char_data(const lcd_8bit_t *lcd , uint8 data){
        std_returntype ret = E_OK;
    uint8 l_pin_counter = ZERO_INIT;
    if(NULL == lcd){
        ret = E_NOT_OK;
    }
    else{
        /* R/W Pin connected to the GND -> Logic (0) "Hard Wired" */
        /* Write Logic (1) to the "Register Select" Pin to select the "Data Register"  */
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), HIGH);
        /* Send the Data through the (8-Pins" Data lines */
        for(l_pin_counter=0; l_pin_counter<8; ++l_pin_counter){
            ret = gpio_pin_write_logic(&(lcd->lcd_data[l_pin_counter]), (data >> l_pin_counter) & (uint8)0x01);
        }
        /* Send the Enable Signal on the "E" Pin */
        ret = lcd_8bits_sned_enable_signal(lcd);
    }
    return ret;
}
std_returntype lcd_8bit_send_char_data_pos(const lcd_8bit_t *lcd , uint8 row, uint8 column, uint8 data){
         std_returntype ret = E_OK;
       if(NULL==lcd){
           ret = E_NOT_OK ;
       } 
       else
        {
           ret = lcd_8bits_set_cursor(lcd , row , column);
           ret = lcd_8bit_send_char_data(lcd , data);
       }
     return ret;
}
std_returntype lcd_8bit_send_string(const lcd_8bit_t *lcd , uint8 *str){
         std_returntype ret = E_OK;
       if(NULL==lcd){
           ret = E_NOT_OK ;
       } 
       else
        {
           while(*str){
               ret = lcd_8bit_send_char_data(lcd , *str++);
           }
       }
     return ret;
}
std_returntype lcd_8bit_send_string_pos(const lcd_8bit_t *lcd , uint8 row, uint8 column, uint8 *str){
         std_returntype ret = E_OK;
       if(NULL==lcd){
           ret = E_NOT_OK ;
       } 
       else
        {
           ret = lcd_8bits_set_cursor(lcd , row , column);
            
               ret = lcd_8bit_send_string(lcd , str);
       }
     return ret;
}
std_returntype lcd_8bit_send_custome_char(const lcd_8bit_t *lcd , uint8 row, uint8 column,
                                          const uint8 _chr[], uint8 mem_pos){
         std_returntype ret = E_OK;
         uint8 lcd_counter = ZERO_INIT;
       if(NULL==lcd){
           ret = E_NOT_OK ;
       } 
       else
        {
           ret = lcd_8bit_send_command(lcd, (_LCD_CGRAM_START+(mem_pos*9)));
           for(lcd_counter=0; lcd_counter<=7;++lcd_counter){
               ret = lcd_8bit_send_char_data(lcd ,_chr[lcd_counter]);
           }
           ret = lcd_8bit_send_char_data_pos(lcd , row , column , mem_pos);
       }
     return ret;
}

std_returntype convert_byte_to_string(uint8 value, uint8 *str){
     std_returntype ret = E_OK;
       if(NULL==str){
           ret = E_NOT_OK ;
       } 
       else
        {
           memset((char *)str , '\0' , 4);
           sprintf(str , "%i" , value);
       }
     return ret;
}
std_returntype convert_short_to_string(uint16 value, uint8 *str){
     std_returntype ret = E_OK;
      uint8 Temp_String[6] = {0};
    uint8 DataCounter = 0;
    if(NULL == str){
        ret = E_NOT_OK;
    }
    else{    
        memset(str, ' ', 5);
        str[5] = '\0';
        sprintf((char *)Temp_String, "%i", value);
        while(Temp_String[DataCounter] != '\0'){
            str[DataCounter] = Temp_String[DataCounter]; 
            DataCounter++;
        }
    }
    return ret;

}
std_returntype convert_int_to_string(uint32 value, uint8 *str){
     std_returntype ret = E_OK;
       if(NULL==str){
           ret = E_NOT_OK ;
       } 
       else
        {
           memset((char *)str , '\0' , 11);
           sprintf(str , "%i" , value);
       }
     return ret;
}
static std_returntype lcd_send_4bits(const lcd_4bit_t *lcd, uint8 _data_command){
     std_returntype ret = E_OK;
     ret = gpio_pin_write_logic(&(lcd->lcd_data[0]), (_data_command >> 0)& (uint8)0x01);
     ret = gpio_pin_write_logic(&(lcd->lcd_data[1]), (_data_command >> 1)& (uint8)0x01);
     ret = gpio_pin_write_logic(&(lcd->lcd_data[2]), (_data_command >> 2)& (uint8)0x01);
     ret = gpio_pin_write_logic(&(lcd->lcd_data[3]), (_data_command >> 3)& (uint8)0x01);
          return ret;
        
}

static std_returntype lcd_4bits_sned_enable_signal(const lcd_4bit_t *lcd){
     std_returntype ret = E_OK;
     ret = gpio_pin_write_logic(&(lcd->lcd_en),HIGH);
     __delay_us(5);
     ret = gpio_pin_write_logic(&(lcd->lcd_en),LOW);
          return ret;   
}

static std_returntype lcd_8bits_sned_enable_signal(const lcd_8bit_t *lcd){
     std_returntype ret = E_OK;
     ret = gpio_pin_write_logic(&(lcd->lcd_en),HIGH);
     __delay_us(5);
     ret = gpio_pin_write_logic(&(lcd->lcd_en),LOW);
     return ret;   
}
static std_returntype lcd_8bits_set_cursor(const lcd_8bit_t *lcd , uint8 row , uint8 column){
    std_returntype ret = E_OK;
    column--;
    switch(row){
        case(ROW1): ret = ret = lcd_8bit_send_command(lcd,0x80 + column);break;
        case(ROW2): ret = ret = lcd_8bit_send_command(lcd,0xC0 + column);break;
        case(ROW3): ret = ret = lcd_8bit_send_command(lcd,0x94 + column);break;
        case(ROW4): ret = ret = lcd_8bit_send_command(lcd,0xD4 + column);break;
        default :;
    }
    return ret; 
}
static std_returntype lcd_4bits_set_cursor(const lcd_4bit_t *lcd , uint8 row , uint8 column){
    std_returntype ret = E_OK;
    column--;
    switch(row){
        case(ROW1): ret = ret = lcd_4bit_send_command(lcd,0x80 + column);break;
        case(ROW2): ret = ret = lcd_4bit_send_command(lcd,0xC0 + column);break;
        case(ROW3): ret = ret = lcd_4bit_send_command(lcd,0x94 + column);break;
        case(ROW4): ret = ret = lcd_4bit_send_command(lcd,0xD4 + column);break;
        default :;
    }
    return ret; 
}