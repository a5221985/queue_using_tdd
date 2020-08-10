################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../google_test_lib/gtest/gtest-all.cc 

CC_DEPS += \
./google_test_lib/gtest/gtest-all.d 

OBJS += \
./google_test_lib/gtest/gtest-all.o 


# Each subdirectory must supply rules for building sources it contributes
google_test_lib/gtest/%.o: ../google_test_lib/gtest/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++2a -I"/Users/am/eclipse-workspace/tdd_for_cpp_project_poc/google_test_lib" -O0 -g3 -ftest-coverage -fprofile-arcs -Wall -c -fmessage-length=0 -fprofile-arcs -ftest-coverage -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


