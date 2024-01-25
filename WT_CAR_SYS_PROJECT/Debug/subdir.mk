################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../DIO_program.c \
../EXTI_program.c \
../Global_Interrupt_program.c \
../HDCMOTOR_program.c \
../HSERVO_program.c \
../MSPI_program.c \
../MUART_program.c \
../TIMER0_program.c \
../TIMER1_program.c \
../main.c \
../seven_segment_program.c 

OBJS += \
./ADC_program.o \
./DIO_program.o \
./EXTI_program.o \
./Global_Interrupt_program.o \
./HDCMOTOR_program.o \
./HSERVO_program.o \
./MSPI_program.o \
./MUART_program.o \
./TIMER0_program.o \
./TIMER1_program.o \
./main.o \
./seven_segment_program.o 

C_DEPS += \
./ADC_program.d \
./DIO_program.d \
./EXTI_program.d \
./Global_Interrupt_program.d \
./HDCMOTOR_program.d \
./HSERVO_program.d \
./MSPI_program.d \
./MUART_program.d \
./TIMER0_program.d \
./TIMER1_program.d \
./main.d \
./seven_segment_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


