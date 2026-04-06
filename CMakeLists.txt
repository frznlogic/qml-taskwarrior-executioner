cmake_minimum_required(VERSION 3.25)

project(QmlTaskwarriorExecutioner)

include(GNUInstallDirs)

find_package(Qt6 REQUIRED COMPONENTS Core Qml Network Quick Positioning Widgets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")

cmake_policy(SET CMP0071 NEW)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

qt_internal_add_qml_module(qml-taskwarrior-executioner
    URI net.frozentux.qmlcomponents
    VERSION 0.1
    CLASS_NAME Qml_Taskwarrior_ExecutionerPlugin
    NO_GENERATE_PLUGIN_SOURCE
    SOURCES
        qml-taskwarrior-executioner_plugin.cpp
        qml-taskwarrior-executioner_plugin.h
        taskwarrior.cpp
        taskwarrior.h
)

target_link_libraries(qml-taskwarrior-executioner PRIVATE
    Qt6::Core
    Qt6::Qml
    Qt6::Network
    Qt6::Quick
    Qt6::Positioning
)
