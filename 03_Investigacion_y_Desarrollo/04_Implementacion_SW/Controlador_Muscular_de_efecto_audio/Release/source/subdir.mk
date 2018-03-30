################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/board.c \
../source/clock_config.c \
../source/main.c \
../source/mtb.c \
../source/pin_mux.c 

OBJS += \
./source/board.o \
./source/clock_config.o \
./source/main.o \
./source/mtb.o \
./source/pin_mux.o 

C_DEPS += \
./source/board.d \
./source/clock_config.d \
./source/main.d \
./source/mtb.d \
./source/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -D__REDLIB__ -I"D:\Maestria\APSW\Switch_De_Distorcion_Ergonomico\Switch_De_Distorcion_Ergonomico\03_Investigacion_y_Desarrollo\04_Implementacion_SW\Controlador_Muscular_de_efecto_audio\source" -I"D:\Maestria\APSW\Switch_De_Distorcion_Ergonomico\Switch_De_Distorcion_Ergonomico\03_Investigacion_y_Desarrollo\04_Implementacion_SW\Controlador_Muscular_de_efecto_audio" -I"D:\Maestria\APSW\Switch_De_Distorcion_Ergonomico\Switch_De_Distorcion_Ergonomico\03_Investigacion_y_Desarrollo\04_Implementacion_SW\Controlador_Muscular_de_efecto_audio\drivers" -I"D:\Maestria\APSW\Switch_De_Distorcion_Ergonomico\Switch_De_Distorcion_Ergonomico\03_Investigacion_y_Desarrollo\04_Implementacion_SW\Controlador_Muscular_de_efecto_audio\utilities" -I"D:\Maestria\APSW\Switch_De_Distorcion_Ergonomico\Switch_De_Distorcion_Ergonomico\03_Investigacion_y_Desarrollo\04_Implementacion_SW\Controlador_Muscular_de_efecto_audio\startup" -I"D:\Maestria\APSW\Switch_De_Distorcion_Ergonomico\Switch_De_Distorcion_Ergonomico\03_Investigacion_y_Desarrollo\04_Implementacion_SW\Controlador_Muscular_de_efecto_audio\CMSIS" -Os -fno-common -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


