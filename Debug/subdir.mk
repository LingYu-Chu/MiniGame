################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../gotkey.c \
../init-default.c \
../init-soc.c \
../interrupt.c \
../lcd.c \
../main.c 

S_UPPER_SRCS += \
../crt0.S 

OBJS += \
./crt0.o \
./gotkey.o \
./init-default.o \
./init-soc.o \
./interrupt.o \
./lcd.o \
./main.o 

C_DEPS += \
./gotkey.d \
./init-default.d \
./init-soc.d \
./interrupt.d \
./lcd.d \
./main.d 

S_UPPER_DEPS += \
./crt0.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


