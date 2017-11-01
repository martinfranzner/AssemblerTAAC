cmake_minimum_required(VERSION 3.8)
project(TaacCerto)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp
        src/Executor.hpp
        src/Executor.cpp
        src/EmachineController.cpp
        src/EmachineController.hpp
        src/Memory.hpp
        src/Memory.cpp
        src/catch.hpp

        TestesExemplo.cpp)
add_executable(TaacCerto ${SOURCE_FILES})