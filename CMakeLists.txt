cmake_minimum_required(VERSION 3.10)

project(LetterCore LANGUAGES C CXX)

set(SOURCE
        src/main.cpp
        src/BufferPacker.cpp include/BufferPacker.h
        src/CommandSender.cpp src/CommandSender.h
        )

include_directories(include)

add_executable(lettercore ${SOURCE})