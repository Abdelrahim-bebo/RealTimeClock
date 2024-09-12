/* 
 * File:   mcal_interrupt_manager.c
 * Author: hp
 *
 * Created on July 1, 2024, 8:07 PM
 */

#include "mcal_interrupt_manager.h"

static volatile uint8 RB4_flag = 1, RB5_flag = 1, RB6_flag = 1, RB7_flag = 1;

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE

void __interrupt() InterruptManagerHigh(void){
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE)&&(INTERRUPT_OCUUR == INTCONbits.INT0IF)){
        INT0_ISR();
    }
    else{/*No thing*/}
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE)&&(INTERRUPT_OCUUR == INTCON3bits.INT2IF)){
        INT2_ISR();
    }
    else{/*No thing*/}
}

void __interrupt(low_priority) InterruptManagerLow(void){
    if((INTERRUPT_ENABLE == INTCON3bits.INT1E)&&(INTERRUPT_OCUUR == INTCON3bits.INT1IF)){
        INT1_ISR();
    }
    else{/*No thing*/}
}
#else

void __interrupt() InterruptManagerHigh(void){
    
 if((INTERRUPT_ENABLE == INTCONbits.TMR0IE) && (INTERRUPT_OCUUR == INTCONbits.TMR0IF)){
     TMR0_ISR();
 }
 else{ /* Nothing */ }

 
}

#endif