################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/APP/main.c" \
"../Sources/APP/sa_mtb.c" \

C_SRCS += \
../Sources/APP/main.c \
../Sources/APP/sa_mtb.c \

OBJS += \
./Sources/APP/main.o \
./Sources/APP/sa_mtb.o \

C_DEPS += \
./Sources/APP/main.d \
./Sources/APP/sa_mtb.d \

OBJS_QUOTED += \
"./Sources/APP/main.o" \
"./Sources/APP/sa_mtb.o" \

C_DEPS_QUOTED += \
"./Sources/APP/main.d" \
"./Sources/APP/sa_mtb.d" \

OBJS_OS_FORMAT += \
./Sources/APP/main.o \
./Sources/APP/sa_mtb.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/APP/main.o: ../Sources/APP/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/APP/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/APP/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/APP/sa_mtb.o: ../Sources/APP/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/APP/sa_mtb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/APP/sa_mtb.o"
	@echo 'Finished building: $<'
	@echo ' '


