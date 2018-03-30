################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/HIL/Distorcion.c" \
"../Sources/HIL/Echo.c" \
"../Sources/HIL/Electromiografo.c" \
"../Sources/HIL/Inicializacion.c" \
"../Sources/HIL/NoEfect.c" \
"../Sources/HIL/Vibrato.c" \

C_SRCS += \
../Sources/HIL/Distorcion.c \
../Sources/HIL/Echo.c \
../Sources/HIL/Electromiografo.c \
../Sources/HIL/Inicializacion.c \
../Sources/HIL/NoEfect.c \
../Sources/HIL/Vibrato.c \

OBJS += \
./Sources/HIL/Distorcion.o \
./Sources/HIL/Echo.o \
./Sources/HIL/Electromiografo.o \
./Sources/HIL/Inicializacion.o \
./Sources/HIL/NoEfect.o \
./Sources/HIL/Vibrato.o \

C_DEPS += \
./Sources/HIL/Distorcion.d \
./Sources/HIL/Echo.d \
./Sources/HIL/Electromiografo.d \
./Sources/HIL/Inicializacion.d \
./Sources/HIL/NoEfect.d \
./Sources/HIL/Vibrato.d \

OBJS_QUOTED += \
"./Sources/HIL/Distorcion.o" \
"./Sources/HIL/Echo.o" \
"./Sources/HIL/Electromiografo.o" \
"./Sources/HIL/Inicializacion.o" \
"./Sources/HIL/NoEfect.o" \
"./Sources/HIL/Vibrato.o" \

C_DEPS_QUOTED += \
"./Sources/HIL/Distorcion.d" \
"./Sources/HIL/Echo.d" \
"./Sources/HIL/Electromiografo.d" \
"./Sources/HIL/Inicializacion.d" \
"./Sources/HIL/NoEfect.d" \
"./Sources/HIL/Vibrato.d" \

OBJS_OS_FORMAT += \
./Sources/HIL/Distorcion.o \
./Sources/HIL/Echo.o \
./Sources/HIL/Electromiografo.o \
./Sources/HIL/Inicializacion.o \
./Sources/HIL/NoEfect.o \
./Sources/HIL/Vibrato.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/HIL/Distorcion.o: ../Sources/HIL/Distorcion.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/HIL/Distorcion.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/HIL/Distorcion.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/HIL/Echo.o: ../Sources/HIL/Echo.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/HIL/Echo.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/HIL/Echo.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/HIL/Electromiografo.o: ../Sources/HIL/Electromiografo.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/HIL/Electromiografo.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/HIL/Electromiografo.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/HIL/Inicializacion.o: ../Sources/HIL/Inicializacion.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/HIL/Inicializacion.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/HIL/Inicializacion.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/HIL/NoEfect.o: ../Sources/HIL/NoEfect.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/HIL/NoEfect.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/HIL/NoEfect.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/HIL/Vibrato.o: ../Sources/HIL/Vibrato.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/HIL/Vibrato.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/HIL/Vibrato.o"
	@echo 'Finished building: $<'
	@echo ' '


