################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Cell.cpp \
../Error.cpp \
../Exception.cpp \
../Matrix.cpp \
../Pos.cpp \
../SudokuSolver.cpp \
../pgm.cpp 

OBJS += \
./Cell.o \
./Error.o \
./Exception.o \
./Matrix.o \
./Pos.o \
./SudokuSolver.o \
./pgm.o 

CPP_DEPS += \
./Cell.d \
./Error.d \
./Exception.d \
./Matrix.d \
./Pos.d \
./SudokuSolver.d \
./pgm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


