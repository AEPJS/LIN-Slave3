################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Application/Application.c" \

C_SRCS += \
../Sources/Application/Application.c \

OBJS += \
./Sources/Application/Application_c.obj \

OBJS_QUOTED += \
"./Sources/Application/Application_c.obj" \

C_DEPS += \
./Sources/Application/Application_c.d \

OBJS_OS_FORMAT += \
./Sources/Application/Application_c.obj \

C_DEPS_QUOTED += \
"./Sources/Application/Application_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Application/Application_c.obj: ../Sources/Application/Application.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Application/Application.args" -o "Sources/Application/Application_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Application/%.d: ../Sources/Application/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


