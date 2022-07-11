cmake_minimum_required(VERSION 3.10)

project(LightCore)

set(SOURCE
        src/main.cpp
        src/LightCore.cpp
        src/MatrixState.cpp
        src/LightInterface.cpp
        )

include_directories(include)

add_executable(lightcore ${SOURCE})