################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/all_tests.cpp \
../test/queue_test.cpp 

OBJS += \
./test/all_tests.o \
./test/queue_test.o 

CPP_DEPS += \
./test/all_tests.d \
./test/queue_test.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -I../google_test_lib -I../src -O0 -g3 -ftest-coverage -fprofile-arcs -Wall -c -fmessage-length=0 -fprofile-arcs -ftest-coverage -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


