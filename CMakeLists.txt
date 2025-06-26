cmake_minimum_required(VERSION 3.4)

project(QmlTaskwarriorExecutioner)

include(GNUInstallDirs)

list(APPEND CMAKE_PREFIX_PATH "/home/osan/Qt/6.9.1/gcc_64/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Core Qml Network Quick Positioning Widgets)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")

set(INSTALLATION_LOCATION ${CMAKE_INSTALL_DATADIR}/QmlMirror)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(QT_QML_MODULES_LOCATION lib/qt6/qml)

macro(add_qml_plugin PLUGIN_ID SOURCE_FILES)

    string(REPLACE "." "/" PLUGIN_PATH "net.frozentux.qmlcomponents")

    set(PLUGIN_INSTALLATION_PATH ${QT_QML_MODULES_LOCATION}/${PLUGIN_PATH})
    add_library(${PLUGIN_ID} SHARED ${SOURCE_FILES})
    target_link_libraries(${PLUGIN_ID} PRIVATE Qt6::Core Qt6::Qml Qt6::Network Qt6::Quick Qt6::Positioning)

    install(TARGETS ${PLUGIN_ID} DESTINATION ${PLUGIN_INSTALLATION_PATH})

    # Set the library file name to be the last token of the plugin ID
    string(REPLACE "." ";" PLUGIN_LIB_NAME ${PLUGIN_ID})
    list(GET PLUGIN_LIB_NAME -1 PLUGIN_LIB_NAME)

    set(PLUGIN_LOCATION_IN_BUILD ${CMAKE_BINARY_DIR}/plugins/${PLUGIN_PATH})

    configure_file(qmldir ${PLUGIN_LOCATION_IN_BUILD}/qmldir COPYONLY)
    install(FILES ${PLUGIN_LOCATION_IN_BUILD}/qmldir DESTINATION ${PLUGIN_INSTALLATION_PATH})
    set_target_properties(${PLUGIN_ID} PROPERTIES
        OUTPUT_NAME ${PLUGIN_LIB_NAME}
        QT_QML_MODULE_VERSION 1.0
        QT_QML_MODULE_URI qml-taskwarrior-executioner
        LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_LOCATION_IN_BUILD}
        RUNTIME_OUTPUT_DIRECTORY ${PLUGIN_LOCATION_IN_BUILD}
    )
    qt_policy(SET QTP0001 NEW)
    qt_add_qml_module(${PLUGIN_ID}
                        URI qml-taskwarrior-executioner
                        VERSION 0.1.0 
                        SOURCES ${SOURCE_FILES}
    )

endmacro()

set(SOURCE_FILES
    qml-taskwarrior-executioner_plugin.cpp
    qml-taskwarrior-executioner_plugin.h
    taskwarrior.cpp
    taskwarrior.h
)


add_qml_plugin(qml-taskwarrior-executioner "${SOURCE_FILES}")



