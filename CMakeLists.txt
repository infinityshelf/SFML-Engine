cmake_minimum_required(VERSION 3.7)
project(SFML_Engine)

set(CMAKE_CXX_STANDARD 14)
set(PLAYER ./Player)
set(WORLD ./World)
include_directories(${PLAYER})
include_directories(${WORLD})

set(SOURCE_FILES
        Entity.hpp
        main.cpp
        ${PLAYER}/Player.cpp
        ${PLAYER}/Player.hpp
        ${WORLD}/World.cpp
        ${WORLD}/World.hpp Input/Input.cpp Input/Input.hpp Input/InputStruct.hpp Input/InputListener.hpp)

add_executable(SFML_Engine ${SOURCE_FILES})

target_link_libraries(SFML_Engine -lsfml-graphics -lsfml-window -lsfml-system)