################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/HAL/ADC_Driver.c" \
"../Sources/HAL/DACDriver.c" \
"../Sources/HAL/GPIODriver.c" \
"../Sources/HAL/PITDriver.c" \

C_SRCS += \
../Sources/HAL/ADC_Driver.c \
../Sources/HAL/DACDriver.c \
../Sources/HAL/GPIODriver.c \
../Sources/HAL/PITDriver.c \

OBJS += \
./Sources/HAL/ADC_Driver.o \
./Sources/HAL/DACDriver.o \
./Sources/HAL/GPIODriver.o \
./Sources/HAL/PITDriver.o \

C_DEPS += \
./Sources/HAL/ADC_Driver.d \
./Sources/HAL/DACDriver.d \
./Sources/HAL/GPIODriver.d \
./Sources/HAL/PITDriver.d \

OBJS_QUOTED += \
"./Sources/HAL/ADC_Driver.o" \
"./Sources/HAL/DACDriver.o" \
"./Sources/HAL/GPIODriver.o" \
"./Sources/HAL/PITDriver.o" \

C_DEPS_QUOTED += \
"./Sources/HAL/ADC_Driver.d" \
"./Sources/HAL/DACDriver.d" \
"./Sources/HAL/GPIODriver.d" \
"./Sources/HAL/PITDriver.d" \

OBJS_OS_FORMAT += \
./Sources/HAL/ADC_Driver.o \
./Sources/HAL/DACDriver.o \
./Sources/HAL/GPIODriver.o \
./Sources/HAL/PITDriver.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/HAL/ADC_Driver.o: ../Sources/HAL/ADC_Driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/HAL/ADC_Driver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/HAL/ADC_Driver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/HAL/DACDriver.o: ../Sources/HAL/DACDriver.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/HAL/DACDriver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/HAL/DACDriver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/HAL/GPIODriver.o: ../Sources/HAL/GPIODriver.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/HAL/GPIODriver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/HAL/GPIODriver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/HAL/PITDriver.o: ../Sources/HAL/PITDriver.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/HAL/PITDriver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/HAL/PITDriver.o"
	@echo 'Finished building: $<'
	@echo ' '


