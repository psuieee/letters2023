cmake_minimum_required(VERSION 3.10)

project(LetterCore)

set(SOURCE
        src/main.cpp
        src/BufferPacker.cpp
        src/CommandSender.cpp
        src/Pattern.cpp
        )

include_directories(include)

add_executable(lettercore ${SOURCE})