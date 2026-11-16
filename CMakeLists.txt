cmake_minimum_required(VERSION 3.16)
project(EditeurCpp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(EditeurCpp
    src/main.cpp
    src/MainWindow.h
    src/MainWindow.cpp
    src/CodeEditor.h
    src/CodeEditor.cpp
)

target_link_libraries(EditeurCpp PRIVATE Qt6::Widgets)
