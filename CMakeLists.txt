cmake_minimum_required(VERSION 3.8)
project(TaacCerto)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp
        src/CPU/CPU.hpp
        src/CPU/CPU.cpp
        src/Loader/Loader.cpp
        src/Loader/Loader.hpp
        src/Memory/Memory.hpp
        src/Memory/Memory.cpp
        src/catch.hpp
        src/TestesExemplo.cpp
        src/Controller/Controller.cpp
        src/Controller/Controller.h
        src/Cache/Cache.cpp
        src/Cache/Cache.h
        src/Helper/Helper.cpp
        src/Helper/Helper.h
        src/TestesExemplo.cpp
        src/MemoryAddres/MemoryAddress.cpp
        src/MemoryAddres/MemoryAddress.h
        src/CacheLine/CacheLine.cpp src/CacheLine/CacheLine.h)
add_executable(TaacCerto ${SOURCE_FILES})