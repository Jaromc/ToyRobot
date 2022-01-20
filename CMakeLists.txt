cmake_minimum_required(VERSION 3.10)

project(ToyRobot VERSION 1.0)

set (Project_SOURCES
        ${SOURCE_DIR}main.cpp
        ${SOURCE_DIR}ToyRobot.cpp
    )

add_executable( ToyRobot ${Project_SOURCES} )