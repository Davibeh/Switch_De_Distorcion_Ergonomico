################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/app_ADC.c \
../Application/app_BtnDbnc.c \
../Application/app_DAC.c \
../Application/app_GPIO.c \
../Application/app_Init.c \
../Application/app_LED.c \
../Application/app_PIT.c \
../Application/app_PWM.c 

OBJS += \
./Application/app_ADC.o \
./Application/app_BtnDbnc.o \
./Application/app_DAC.o \
./Application/app_GPIO.o \
./Application/app_Init.o \
./Application/app_LED.o \
./Application/app_PIT.o \
./Application/app_PWM.o 

C_DEPS += \
./Application/app_ADC.d \
./Application/app_BtnDbnc.d \
./Application/app_DAC.d \
./Application/app_GPIO.d \
./Application/app_Init.d \
./Application/app_LED.d \
./Application/app_PIT.d \
./Application/app_PWM.d 


# Each subdirectory must supply rules for building sources it contributes
Application/%.o: ../Application/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -D__REDLIB__ -I"D:\Maestria\APSW\Switch_De_Distorcion_Ergonomico\Switch_De_Distorcion_Ergonomico\03_Investigacion_y_Desarrollo\04_Implementacion_SW\Controlador_Muscular_de_efecto_audio" -I"D:\Maestria\APSW\Switch_De_Distorcion_Ergonomico\Switch_De_Distorcion_Ergonomico\03_Investigacion_y_Desarrollo\04_Implementacion_SW\Controlador_Muscular_de_efecto_audio\drivers" -I"D:\Maestria\APSW\Switch_De_Distorcion_Ergonomico\Switch_De_Distorcion_Ergonomico\03_Investigacion_y_Desarrollo\04_Implementacion_SW\Controlador_Muscular_de_efecto_audio\startup" -I"D:\Maestria\APSW\Switch_De_Distorcion_Ergonomico\Switch_De_Distorcion_Ergonomico\03_Investigacion_y_Desarrollo\04_Implementacion_SW\Controlador_Muscular_de_efecto_audio\CMSIS" -I"D:\Maestria\APSW\Switch_De_Distorcion_Ergonomico\Switch_De_Distorcion_Ergonomico\03_Investigacion_y_Desarrollo\04_Implementacion_SW\Controlador_Muscular_de_efecto_audio\source" -I"D:\Maestria\APSW\Switch_De_Distorcion_Ergonomico\Switch_De_Distorcion_Ergonomico\03_Investigacion_y_Desarrollo\04_Implementacion_SW\Controlador_Muscular_de_efecto_audio\Application" -I"D:\Maestria\APSW\Switch_De_Distorcion_Ergonomico\Switch_De_Distorcion_Ergonomico\03_Investigacion_y_Desarrollo\04_Implementacion_SW\Controlador_Muscular_de_efecto_audio\OS" -I"D:\Maestria\APSW\Switch_De_Distorcion_Ergonomico\Switch_De_Distorcion_Ergonomico\03_Investigacion_y_Desarrollo\04_Implementacion_SW\Controlador_Muscular_de_efecto_audio\utilities" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


