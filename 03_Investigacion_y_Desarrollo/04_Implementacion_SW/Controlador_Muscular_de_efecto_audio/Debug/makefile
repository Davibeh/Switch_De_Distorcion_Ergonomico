################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include utilities/subdir.mk
-include startup/subdir.mk
-include source/subdir.mk
-include drivers/subdir.mk
-include OS/subdir.mk
-include CMSIS/subdir.mk
-include Application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Controlador_Muscular_de_efecto_audio.axf

dependents:
	-cd D:/Maestria/APSW/Switch_De_Distorcion_Ergonomico/Switch_De_Distorcion_Ergonomico/03_Investigacion_y_Desarrollo/04_Implementacion_SW/Controlador_Muscular_de_efecto_audio/Release && $(MAKE) clean all

# Tool invocations
Controlador_Muscular_de_efecto_audio.axf: $(OBJS) $(USER_OBJS) D:/Maestria/APSW/Switch_De_Distorcion_Ergonomico/Switch_De_Distorcion_Ergonomico/03_Investigacion_y_Desarrollo/04_Implementacion_SW/Controlador_Muscular_de_efecto_audio/Release/Controlador_Muscular_de_efecto_audio.axf
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="Controlador_Muscular_de_efecto_audio.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m0plus -mthumb -T Controlador_Muscular_de_efecto_audio_Debug.ld -o "Controlador_Muscular_de_efecto_audio.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Controlador_Muscular_de_efecto_audio.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Controlador_Muscular_de_efecto_audio.axf"; # arm-none-eabi-objcopy -v -O binary "Controlador_Muscular_de_efecto_audio.axf" "Controlador_Muscular_de_efecto_audio.bin" ; # checksum -p MKL25Z128xxx4 -d "Controlador_Muscular_de_efecto_audio.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build
D:/Maestria/APSW/Switch_De_Distorcion_Ergonomico/Switch_De_Distorcion_Ergonomico/03_Investigacion_y_Desarrollo/04_Implementacion_SW/Controlador_Muscular_de_efecto_audio/Release/Controlador_Muscular_de_efecto_audio.axf:

-include ../makefile.targets
