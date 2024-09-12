
/* 
 * File:   mcal_external_interrupt.c
 * Author: hp
 *
 * Created on July 1, 2024, 8:07 PM
 */

#include "mcal_external_interrupt.h"

static void(*INT0_InterruptHandler)(void) = NULL;
static void(*INT1_InterruptHandler)(void) = NULL;
static void(*INT2_InterruptHandler)(void) = NULL;

static void(*RB4_InterruptHandler_High)(void) = NULL;
static void(*RB4_InterruptHandler_Low)(void) = NULL;
static void(*RB5_InterruptHandler_High)(void) = NULL;
static void(*RB5_InterruptHandler_Low)(void) = NULL;
static void(*RB6_InterruptHandler_High)(void) = NULL;
static void(*RB6_InterruptHandler_Low)(void) = NULL;
static void(*RB7_InterruptHandler_High)(void) = NULL;
static void(*RB7_InterruptHandler_Low)(void) = NULL;

static std_returntype Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj);
static std_returntype Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj);
static std_returntype Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_obj);
static std_returntype Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_obj);
static std_returntype Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_obj);
static std_returntype Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj);

static std_returntype INT0_SetInterrupt_handler(void(*InterruptHandler)(void));
static std_returntype INT1_SetInterrupt_handler(void(*InterruptHandler)(void));
static std_returntype INT2_SetInterrupt_handler(void(*InterruptHandler)(void));
static std_returntype Interrupt_INTx_SetInterrupt_handler(const interrupt_INTx_t *int_obj);

static std_returntype Interrupt_RBx_Enable(const interrupt_RBx_t *int_obj);
static std_returntype Interrupt_RBx_Disable(const interrupt_RBx_t *int_obj);
static std_returntype Interrupt_RBx_Priority_Init(const interrupt_RBx_t *int_obj);
static std_returntype Interrupt_RBx_Pin_Init(const interrupt_RBx_t *int_obj);

std_returntype Interrupt_INTx_Init(const interrupt_INTx_t *int_obj){
     std_returntype ret = E_NOT_OK ;
      if(NULL==int_obj){
           ret = E_NOT_OK ;
       } 
       else
        {
          /*Disable the external interrupt*/
          ret = Interrupt_INTx_Disable(int_obj);
          /*Clear interrupt flag : External interrupt did not occur*/
          ret = Interrupt_INTx_Clear_Flag(int_obj);
          /*Configure External interrupt edge*/
          ret = Interrupt_INTx_Edge_Init(int_obj);
          #if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
            /*Configure External interrupt priority*/
          ret = Interrupt_INTx_Priority_Init(int_obj);
          #endif
          /*Configure External interrupt I/O pin*/
          ret = Interrupt_INTx_Pin_Init(int_obj);
          /*Configure External interrupt callback*/
          ret = Interrupt_INTx_SetInterrupt_handler(int_obj);
          /*Enable the external interrupt*/
          ret = Interrupt_INTx_Enable(int_obj);
       }
     return ret;
}

void INT0_ISR(void){
         /*the INT0 external interrupt occured (must be cleared in software)*/
         EXT_INT0_InterruptFlagClear();
         /*Code*/
         
         /*Callback function gets called every time this ISR executes*/
         if(INT0_InterruptHandler){INT0_InterruptHandler();}
     }

void INT1_ISR(void){
         /*the INT1 external interrupt occured (must be cleared in software)*/
         EXT_INT1_InterruptFlagClear();
         /*Code*/
         
         /*Callback function gets called every time this ISR executes*/
         if(INT1_InterruptHandler){INT1_InterruptHandler();}
     }

void INT2_ISR(void){
         /*the INT2 external interrupt occured (must be cleared in software)*/
         EXT_INT2_InterruptFlagClear();
         /*Code*/
         
         /*Callback function gets called every time this ISR executes*/
         if(INT2_InterruptHandler){INT2_InterruptHandler();}
     }

void RB4_ISR(uint8 RB4_Source){
         /*the RB4 external interrupt occured (must be cleared in software)*/
         EXT_RBx_InterruptFlagClear();
         /*Code*/
         
         /*Callback function gets called every time this ISR executes*/
         if(0 == RB4_Source){
             if (RB4_InterruptHandler_High){RB4_InterruptHandler_High();}
         }
         else if(1 == RB4_Source){
             if (RB4_InterruptHandler_Low){RB4_InterruptHandler_Low();}
         }
         else{/*No Thing*/}
         
}

void RB5_ISR(uint8 RB5_Source){
         /*the RB5 external interrupt occured (must be cleared in software)*/
         EXT_RBx_InterruptFlagClear();
         /*Code*/
         
         /*Callback function gets called every time this ISR executes*/
         if(0 == RB5_Source){
             if (RB5_InterruptHandler_High){RB5_InterruptHandler_High();}
         }
         else if(1 == RB5_Source){
             if (RB5_InterruptHandler_Low){RB5_InterruptHandler_Low();}
         }
         else{/*No Thing*/}
         
}

void RB6_ISR(uint8 RB6_Source){
         /*the RB6 external interrupt occured (must be cleared in software)*/
         EXT_RBx_InterruptFlagClear();
         /*Code*/
         
         /*Callback function gets called every time this ISR executes*/
         if(0 == RB6_Source){
             if (RB6_InterruptHandler_High){RB6_InterruptHandler_High();}
         }
         else if(1 == RB6_Source){
             if (RB6_InterruptHandler_Low){RB6_InterruptHandler_Low();}
         }
         else{/*No Thing*/}
         
}

void RB7_ISR(uint8 RB7_Source){
         /*the RB7 external interrupt occured (must be cleared in software)*/
         EXT_RBx_InterruptFlagClear();
         /*Code*/
         
         /*Callback function gets called every time this ISR executes*/
         if(0 == RB7_Source){
             if (RB7_InterruptHandler_High){RB7_InterruptHandler_High();}
         }
         else if(1 == RB7_Source){
             if (RB7_InterruptHandler_Low){RB7_InterruptHandler_Low();}
         }
         else{/*No Thing*/}
         
}

std_returntype Interrupt_INTx_DeInit(const interrupt_INTx_t *int_obj){
    std_returntype ret = E_NOT_OK ;
      if(NULL==int_obj){
           ret = E_NOT_OK ;
       } 
       else
        {
         ret = Interrupt_INTx_Disable(int_obj);
       }
    return ret;
}
std_returntype Interrupt_RBx_Init(const interrupt_RBx_t *int_obj){
    std_returntype ret = E_NOT_OK ;
      if(NULL==int_obj){
           ret = E_NOT_OK ;
       } 
       else
        {
          /*this interrupt clears interrupt disable for external interrupt RBx*/
          EXT_RBx_InterruptDisable();
          /*this routine clears the interrupt flag for the external interrupt RBx*/
          EXT_RBx_InterruptFlagClear();
#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
    INTERRUPT_PriorityLevelEnable();
        if(INTERRUPT_LOW_PRIORITY == int_obj->priority){
            /*this macro will enable low priority glopal interrupt*/
            INTERRUPT_GlopalInterruptLowEnable();
            /*this routine set the RBx external interrupt priority to be low priority*/
            EXT_RBx_Priority_Low();
        }
        else if(INTERRUPT_High_PRIORITY == int_obj->priority){
            /*this macro will enable high priority glopal interrupt*/
            INTERRUPT_GlopalInterruptHighEnable();
            /*this routine set the RBx external interrupt priority to be high priority*/
            EXT_RBx_Priority_High();
        }
        else{/*NO THING*/}
#else
            INTERRUPT_GlopalInterruptEnable();
            INTERRUPT_PeriphralInterruptEnable();
#endif  
            /*initialize the RBx pin to be input*/
            ret = gpio_pin_direction_initialize(&(int_obj->mcu_pin));
            /*initialize the call back function*/
            switch(int_obj->mcu_pin.pin ){
                case PIN4 :
                    RB4_InterruptHandler_High = int_obj->EXT_InterruptHandler_High;
                    RB4_InterruptHandler_Low = int_obj->EXT_InterruptHandler_Low;
                    break;
                case PIN5 :
                    RB5_InterruptHandler_High = int_obj->EXT_InterruptHandler_High;
                    RB5_InterruptHandler_Low = int_obj->EXT_InterruptHandler_Low;
                    break;
                case PIN6 :
                    RB6_InterruptHandler_High = int_obj->EXT_InterruptHandler_High;
                    RB6_InterruptHandler_Low = int_obj->EXT_InterruptHandler_Low;
                    break;
                case PIN7 :
                    RB7_InterruptHandler_High = int_obj->EXT_InterruptHandler_High;
                    RB7_InterruptHandler_Low = int_obj->EXT_InterruptHandler_Low;
                    break;
                default:
                    ret = E_NOT_OK;
            }
          /*this interrupt sets interrupt enable for external interrupt RBx*/
          EXT_RBx_InterruptEnable();
       }
    return ret;
}
std_returntype Interrupt_RBx_DeInit(const interrupt_RBx_t *int_obj){
    std_returntype ret = E_NOT_OK ;
      if(NULL==int_obj){
           ret = E_NOT_OK ;
       } 
       else
        {
          
       }
    return ret;
}

static std_returntype Interrupt_INTx_Enable(const interrupt_INTx_t *int_obj){
    std_returntype ret = E_NOT_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        switch(int_obj->source){
            case INTERRUPT_EXTERNAL_INT0:
                #if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PriorityLevelEnable();
                INTERRUPT_GlopalInterruptHighEnable();
                #else
                INTERRUPT_GlopalInterruptEnable();
                INTERRUPT_PeriphralInterruptEnable();
                #endif
                EXT_INT0_InterruptEnable();
                ret= E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT1:
                #if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PriorityLevelEnable();
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){
                    INTERRUPT_GlopalInterruptLowEnable();
                }
                else if(INTERRUPT_High_PRIORITY == int_obj->priority){
                    INTERRUPT_GlopalInterruptHighEnable();
                }
                else{/*NO THING*/}
                #else
                INTERRUPT_GlopalInterruptEnable();
                INTERRUPT_PeriphralInterruptEnable();
                #endif
                EXT_INT1_InterruptEnable();
                ret= E_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2:
                #if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PriorityLevelEnable();
                if(INTERRUPT_LOW_PRIORITY == int_obj->priority){
                    INTERRUPT_GlopalInterruptLowEnable();
                }
                else if(INTERRUPT_High_PRIORITY == int_obj->priority){
                    INTERRUPT_GlopalInterruptHighEnable();
                }
                else{/*NO THING*/}
                #else
                INTERRUPT_GlopalInterruptEnable();
                INTERRUPT_PeriphralInterruptEnable();
                #endif
                EXT_INT2_InterruptEnable();
                ret= E_OK;
                break;
            default: ret= E_NOT_OK;
        }
    }
    return ret;
}
static std_returntype Interrupt_INTx_Disable(const interrupt_INTx_t *int_obj){
    std_returntype ret = E_NOT_OK ;
      if(NULL==int_obj){
           ret = E_NOT_OK ;
       } 
       else
        {
           switch(int_obj->source){
              case INTERRUPT_EXTERNAL_INT0: 
                  EXT_INT0_InterruptDisable();
                  ret = E_OK; 
                  break;
              case INTERRUPT_EXTERNAL_INT1:
                  EXT_INT1_InterruptDisable(); 
                  ret = E_OK;
                  break;
              case INTERRUPT_EXTERNAL_INT2: 
                  EXT_INT2_InterruptDisable();  
                  ret = E_OK;
                  break;
              default : ret = E_NOT_OK ;
              
          }
       }
    return ret;
}

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
static std_returntype Interrupt_INTx_Priority_Init(const interrupt_INTx_t *int_obj){
    std_returntype ret = E_NOT_OK ;
      if(NULL==int_obj){
           ret = E_NOT_OK ;
       } 
       else
        {
          switch(int_obj->source){
              case INTERRUPT_EXTERNAL_INT1:
                  if(INTERRUPT_LOW_PRIORITY == int_obj->priority){EXT_INT1_LowPrioritySet();}
                  else if(INTERRUPT_High_PRIORITY == int_obj->priority){EXT_INT1_HighPrioritySet();}
                  else{/* No Thing */}
                  ret = E_OK;
                  break;
              case INTERRUPT_EXTERNAL_INT2: 
                  if(INTERRUPT_LOW_PRIORITY == int_obj->priority){EXT_INT2_LowPrioritySet();}
                  else if(INTERRUPT_High_PRIORITY == int_obj->priority){EXT_INT2_HighPrioritySet();}
                  else{/* No Thing */}
                  ret = E_OK;
                  break;
              default : ret = E_NOT_OK ;
              
          }
       }
    return ret;
}
#endif
static std_returntype Interrupt_INTx_Edge_Init(const interrupt_INTx_t *int_obj){
    std_returntype ret = E_NOT_OK ;
      if(NULL==int_obj){
           ret = E_NOT_OK ;
       } 
       else
        {
            switch(int_obj->source){
              case INTERRUPT_EXTERNAL_INT0: 
                  if(INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT0_FallingEdgeSet();}
                  else if(INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT0_RisingEdgeSet();}
                  else{/* No Thing */}
                  ret = E_OK; 
                  break;
              case INTERRUPT_EXTERNAL_INT1:
                  if(INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT1_FallingEdgeSet();}
                  else if(INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT1_RisingEdgeSet();}
                  else{/* No Thing */}
                  ret = E_OK;
                  break;
              case INTERRUPT_EXTERNAL_INT2: 
                  if(INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT2_FallingEdgeSet();}
                  else if(INTERRUPT_FALLING_EDGE == int_obj->edge){EXT_INT2_RisingEdgeSet();}
                  else{/* No Thing */}
                  ret = E_OK;
                  break;
              default : ret = E_NOT_OK ;
              
          }
       }
    return ret;
}

static std_returntype Interrupt_INTx_Pin_Init(const interrupt_INTx_t *int_obj){
      std_returntype ret = E_NOT_OK ;
      if(NULL==int_obj){
           ret = E_NOT_OK ;
       } 
       else
        {
          ret = gpio_pin_direction_initialize(&(int_obj->mcu_pin));
       }
    return ret;
}

static std_returntype Interrupt_INTx_Clear_Flag(const interrupt_INTx_t *int_obj){
     std_returntype ret = E_NOT_OK ;
      if(NULL==int_obj){
           ret = E_NOT_OK ;
       } 
       else
        {
          switch(int_obj->source){
              case INTERRUPT_EXTERNAL_INT0: 
                 EXT_INT0_InterruptFlagClear();
                  ret = E_OK; 
                  break;
              case INTERRUPT_EXTERNAL_INT1:
                 EXT_INT1_InterruptFlagClear();
                  ret = E_OK;
                  break;
              case INTERRUPT_EXTERNAL_INT2: 
                 EXT_INT2_InterruptFlagClear();
                  ret = E_OK;
                  break;
              default : ret = E_NOT_OK ;
              
          }
       }
    return ret;
}

static std_returntype INT0_SetInterrupt_handler(void(*InterruptHandler)(void)){
    std_returntype ret = E_NOT_OK ;
      if(NULL==InterruptHandler){
           ret = E_NOT_OK ;
       } 
       else
        {
          INT0_InterruptHandler = InterruptHandler;
          ret = E_OK;
       }
    return ret;
}

static std_returntype INT1_SetInterrupt_handler(void(*InterruptHandler)(void)){
    std_returntype ret = E_NOT_OK ;
      if(NULL==InterruptHandler){
           ret = E_NOT_OK ;
       } 
       else
        {
          INT1_InterruptHandler = InterruptHandler;
          ret = E_OK;
       }
    return ret;
}

static std_returntype INT2_SetInterrupt_handler(void(*InterruptHandler)(void)){
    std_returntype ret = E_NOT_OK ;
      if(NULL==InterruptHandler){
           ret = E_NOT_OK ;
       } 
       else
        {
          INT2_InterruptHandler = InterruptHandler;
          ret = E_OK;
       }
    return ret;
}

static std_returntype Interrupt_INTx_SetInterrupt_handler(const interrupt_INTx_t *int_obj){
     std_returntype ret = E_NOT_OK ;
      if(NULL==int_obj){
           ret = E_NOT_OK ;
       } 
       else
        {
          switch(int_obj->source){
              case INTERRUPT_EXTERNAL_INT0: 
                ret =  INT0_SetInterrupt_handler(int_obj->EXT_InterruptHandler);    
                  break;
              case INTERRUPT_EXTERNAL_INT1:
                ret =  INT1_SetInterrupt_handler(int_obj->EXT_InterruptHandler); 
                  break;
              case INTERRUPT_EXTERNAL_INT2: 
                ret =  INT2_SetInterrupt_handler(int_obj->EXT_InterruptHandler); 
                  break;
              default : ret = E_NOT_OK ;
              
          }
       }
    return ret;
}
