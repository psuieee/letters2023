cmake_minimum_required(VERSION 3.10)

project(LightCore)

set(SOURCE
        src/main.cpp
        src/LightCore.cpp
        src/MatrixState.cpp
        src/LightInterface.cpp
        src/Pattern.cpp
        )

include_directories(include)
include_directories( ${OpenCV_INCLUDE_DIRS} )

find_package( OpenCV REQUIRED )

add_executable(lightcore ${SOURCE})

target_link_libraries( lightcore ${OpenCV_LIBS} )