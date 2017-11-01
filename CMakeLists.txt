cmake_minimum_required(VERSION 3.8)
project(TaacCerto)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp
        src/Fetcher.hpp
        src/Fetcher.cpp
        src/Loader.cpp
        src/Loader.hpp
        src/Memory.hpp
        src/Memory.cpp
        src/catch.hpp

        TestesExemplo.cpp src/Controller.cpp src/Controller.h)
add_executable(TaacCerto ${SOURCE_FILES})