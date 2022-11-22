cmake_minimum_required(VERSION 3.0)
project(echoclient LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX /usr)
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/websockets/echoclient")

find_package(Qt5Core REQUIRED)
# libqt5websockets5-dev
find_package(Qt5 REQUIRED COMPONENTS WebSockets)

add_executable(echoclient
    echoclient.cpp echoclient.h
    main.cpp
)

# set_target_properties(echoclient PROPERTIES
#    WIN32_EXECUTABLE FALSE
#    MACOSX_BUNDLE FALSE
#)

target_link_libraries(echoclient PUBLIC
    Qt5::Core
    Qt5::WebSockets
    stdc++
)

install(TARGETS echoclient RUNTIME DESTINATION bin)

# install(TARGETS echoclient
#     RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
#     BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
#     LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
# )