#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/RTC.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/RTC.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_layer/keypad/ecu_key_pad.c ECU_layer/LCD/ecu_lcd.c ECU_layer/sev_seg/ecu_sev_seg.c Mcal_layer/GPIO/hal_gpio.c Mcal_layer/interrupt/mcal_interrupt_manager.c Mcal_layer/interrupt/mcal_internal_interrupt.c Mcal_layer/TIMER0/hal_timer0.c Mcal_layer/device_config.c application.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1 ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1 ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1 ${OBJECTDIR}/Mcal_layer/device_config.p1 ${OBJECTDIR}/application.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1.d ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1.d ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1.d ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1.d ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1.d ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1.d ${OBJECTDIR}/Mcal_layer/device_config.p1.d ${OBJECTDIR}/application.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1 ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1 ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1 ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1 ${OBJECTDIR}/Mcal_layer/device_config.p1 ${OBJECTDIR}/application.p1

# Source Files
SOURCEFILES=ECU_layer/keypad/ecu_key_pad.c ECU_layer/LCD/ecu_lcd.c ECU_layer/sev_seg/ecu_sev_seg.c Mcal_layer/GPIO/hal_gpio.c Mcal_layer/interrupt/mcal_interrupt_manager.c Mcal_layer/interrupt/mcal_internal_interrupt.c Mcal_layer/TIMER0/hal_timer0.c Mcal_layer/device_config.c application.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/RTC.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1: ECU_layer/keypad/ecu_key_pad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/keypad" 
	@${RM} ${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1 ECU_layer/keypad/ecu_key_pad.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.d ${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1: ECU_layer/LCD/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LCD" 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 ECU_layer/LCD/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.d ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1: ECU_layer/sev_seg/ecu_sev_seg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/sev_seg" 
	@${RM} ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1 ECU_layer/sev_seg/ecu_sev_seg.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.d ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1: Mcal_layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/GPIO" 
	@${RM} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1 Mcal_layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.d ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1: Mcal_layer/interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/interrupt" 
	@${RM} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1 Mcal_layer/interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1: Mcal_layer/interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/interrupt" 
	@${RM} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1 Mcal_layer/interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1: Mcal_layer/TIMER0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/TIMER0" 
	@${RM} ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1 Mcal_layer/TIMER0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.d ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/device_config.p1: Mcal_layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer" 
	@${RM} ${OBJECTDIR}/Mcal_layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/device_config.p1 Mcal_layer/device_config.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/device_config.d ${OBJECTDIR}/Mcal_layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1: ECU_layer/keypad/ecu_key_pad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/keypad" 
	@${RM} ${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1 ECU_layer/keypad/ecu_key_pad.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.d ${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/keypad/ecu_key_pad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1: ECU_layer/LCD/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LCD" 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 ECU_layer/LCD/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.d ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1: ECU_layer/sev_seg/ecu_sev_seg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/sev_seg" 
	@${RM} ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1 ECU_layer/sev_seg/ecu_sev_seg.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.d ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/sev_seg/ecu_sev_seg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1: Mcal_layer/GPIO/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/GPIO" 
	@${RM} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1 Mcal_layer/GPIO/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.d ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/GPIO/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1: Mcal_layer/interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/interrupt" 
	@${RM} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1 Mcal_layer/interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1: Mcal_layer/interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/interrupt" 
	@${RM} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1 Mcal_layer/interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1: Mcal_layer/TIMER0/hal_timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer/TIMER0" 
	@${RM} ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1 Mcal_layer/TIMER0/hal_timer0.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.d ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/TIMER0/hal_timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Mcal_layer/device_config.p1: Mcal_layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/Mcal_layer" 
	@${RM} ${OBJECTDIR}/Mcal_layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/Mcal_layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Mcal_layer/device_config.p1 Mcal_layer/device_config.c 
	@-${MV} ${OBJECTDIR}/Mcal_layer/device_config.d ${OBJECTDIR}/Mcal_layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Mcal_layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/RTC.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/RTC.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/RTC.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/RTC.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/RTC.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/RTC.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/RTC.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
