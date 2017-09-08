################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../usbdrv


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../usbdrv/main.c \
../usbdrv/oddebug.c \
../usbdrv/usbdrv.c


PREPROCESSING_SRCS +=  \
../usbdrv/usbdrvasm.S


ASM_SRCS += 


OBJS +=  \
usbdrv/main.o \
usbdrv/oddebug.o \
usbdrv/usbdrv.o \
usbdrv/usbdrvasm.o

OBJS_AS_ARGS +=  \
usbdrv/main.o \
usbdrv/oddebug.o \
usbdrv/usbdrv.o \
usbdrv/usbdrvasm.o

C_DEPS +=  \
usbdrv/main.d \
usbdrv/oddebug.d \
usbdrv/usbdrv.d \
usbdrv/usbdrvasm.d

C_DEPS_AS_ARGS +=  \
usbdrv/main.d \
usbdrv/oddebug.d \
usbdrv/usbdrv.d \
usbdrv/usbdrvasm.d

OUTPUT_FILE_PATH +=Atmega32_BootloadHID.elf

OUTPUT_FILE_PATH_AS_ARGS +=Atmega32_BootloadHID.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler







usbdrv/%.o: ../usbdrv/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=16000000L  -I"D:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include"  -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32a -B "D:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32a" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler
usbdrv/usbdrvasm.o: ../usbdrv/usbdrvasm.S
	@echo Building file: $<
	@echo Invoking: AVR/GNU Assembler : 5.4.0
	$(QUOTE)D:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -Wa,-gdwarf2 -x assembler-with-cpp -c -mmcu=atmega32a -B "D:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32a" -I "D:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	


usbdrv/%.o: ../usbdrv/%.S
	@echo Building file: $<
	@echo Invoking: AVR/GNU Assembler : 5.4.0
	$(QUOTE)D:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -Wa,-gdwarf2 -x assembler-with-cpp -c -mmcu=atmega32a -B "D:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32a" -I "D:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\include"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)D:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Atmega32_BootloadHID.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32a -B "D:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.132\gcc\dev\atmega32a"  
	@echo Finished building target: $@
	"D:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Atmega32_BootloadHID.elf" "Atmega32_BootloadHID.hex"
	"D:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "Atmega32_BootloadHID.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Atmega32_BootloadHID.elf" "Atmega32_BootloadHID.a" "Atmega32_BootloadHID.hex" "Atmega32_BootloadHID.lss" "Atmega32_BootloadHID.eep" "Atmega32_BootloadHID.map" "Atmega32_BootloadHID.srec" "Atmega32_BootloadHID.usersignatures"
	