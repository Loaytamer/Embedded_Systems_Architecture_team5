################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../New\ folder/DIO_PROG.c \
../New\ folder/LCD_Prog.c 

OBJS += \
./New\ folder/DIO_PROG.o \
./New\ folder/LCD_Prog.o 

C_DEPS += \
./New\ folder/DIO_PROG.d \
./New\ folder/LCD_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
New\ folder/DIO_PROG.o: ../New\ folder/DIO_PROG.c New\ folder/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"New folder/DIO_PROG.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

New\ folder/LCD_Prog.o: ../New\ folder/LCD_Prog.c New\ folder/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"New folder/LCD_Prog.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


