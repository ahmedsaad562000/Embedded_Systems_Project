################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_PROGRAM.c \
../EEPROM_Program.c \
../GIE_program.c \
../H_BRIDGE_Program.c \
../TWI_Program.c \
../Thermo_Program.c \
../Timer_program.c \
../exti_program.c \
../main.c 

OBJS += \
./DIO_PROGRAM.o \
./EEPROM_Program.o \
./GIE_program.o \
./H_BRIDGE_Program.o \
./TWI_Program.o \
./Thermo_Program.o \
./Timer_program.o \
./exti_program.o \
./main.o 

C_DEPS += \
./DIO_PROGRAM.d \
./EEPROM_Program.d \
./GIE_program.d \
./H_BRIDGE_Program.d \
./TWI_Program.d \
./Thermo_Program.d \
./Timer_program.d \
./exti_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


