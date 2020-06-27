cmake_minimum_required(VERSION 3.17)
project(1Byte)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
## Was previously used to make sure I can Cmake and left as a comment so I remember how adding an executable/target works
#add_executable(competency_test competency_test.cpp)
#a bunch of vars to make making the source code lists easier
set(c_pre Controller/CPU)
set(mem_pre Controller/Memory)
#If the utils ever have to have code implementation and aren't just constants and typedefs
#set(utils_prefix Controller/Utils)
##lists that organize all the source files to be more managable
list(APPEND cpu
	$(c_pre)/CPU/IO/IO.cpp
	$(c_pre)/CPU/Register/Register.cpp
	$(c_pre)/CPU/ALU/ALU.cpp
	$(c_pre)/CPU/CPU.cpp
	$(c_pre)/CPU/Instructions/Instruction.cpp
	$(c_pre)/CPU/CU/CU.cpp
)
list(APPEND mem
	$(mem_pre)/ROM/ROM.cpp
	$(mem_pre)/RAM/RAM.cpp
)
add_executable(1Byte Entry.cpp Controller/Controller.cpp $(cpu) $(mem))
