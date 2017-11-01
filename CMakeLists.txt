cmake_minimum_required(VERSION 3.8)
project(TaacCerto)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp
            Executor.hpp
            Executor.cpp
        EmachineController.cpp
        EmachineController.hpp
        Memory.hpp
        Memory.cpp

        )
add_executable(TaacCerto ${SOURCE_FILES})