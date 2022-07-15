cmake_minimum_required(VERSION 3.10)

project(LightCore)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

set(CMAKE_CXX_FLAGS "-fopenmp")

set(SOURCE
        src/main.cpp
        src/LightCore.cpp
        src/MatrixState.cpp
        src/LightInterface.cpp
        )

include_directories(include)
include_directories( ${OpenCV_INCLUDE_DIRS} )


find_package(Threads REQUIRED)
find_package(OpenCV REQUIRED)

add_executable(LightCore ${SOURCE})

target_link_libraries(LightCore ${OpenCV_LIBS} )
target_link_libraries(LightCore Threads::Threads)