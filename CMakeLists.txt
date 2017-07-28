cmake_minimum_required(VERSION 3.7)
project(SFML_Engine)

set(CMAKE_CXX_STANDARD 14)
#set(PLAYER ./Player)
#set(WORLD ./World)
#include_directories(${PLAYER})
#include_directories(${WORLD})

set(SOURCE_FILES
        Entity.hpp
        main.cpp
        Player.cpp
        Player.hpp
        World.cpp
        World.hpp
        Input.cpp
        Input.hpp
        InputStruct.hpp
        InputListener.hpp
        GraphicsComponent.hpp
        PlayerGraphicsComponent.cpp
        PlayerGraphicsComponent.hpp
        InputComponent.hpp
        PlayerInputComponent.hpp PlayerInputComponent.cpp)

add_executable(SFML-Engine ${SOURCE_FILES})

target_link_libraries(SFML-Engine -lsfml-graphics -lsfml-window -lsfml-system)