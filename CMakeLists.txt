cmake_minimum_required(VERSION 3.8)
project(TaacCerto)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp
        src/CPU.hpp
        src/CPU.cpp
        src/Loader.cpp
        src/Loader.hpp
        src/Memory.hpp
        src/Memory.cpp
        src/catch.hpp
        src/TestesExemplo.cpp
        src/Controller.cpp
        src/Controller.h
        src/Cache.cpp
        src/Cache.h
        src/Helper.cpp
        src/Helper.h
        src/TestesExemplo.cpp
        src/CacheLine.cpp src/CacheLine.h)
add_executable(TaacCerto ${SOURCE_FILES})