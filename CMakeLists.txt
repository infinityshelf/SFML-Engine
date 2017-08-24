set(SFML_ENGINE_SOURCES Entity.hpp
        Input.cpp
        Input.hpp
        InputStruct.hpp
        GraphicsComponent.hpp
        InputComponent.hpp
        TextureManager.cpp
        TextureManager.hpp
        PhysicsComponent.hpp
        Component.hpp
        Component.cpp
        GraphicsComponent.cpp
        ComponentMessaging.hpp
        EntityManager.cpp
        EntityManager.hpp
        CollidableManager.cpp
        CollidableManager.hpp)

add_library(SFML-Engine ${SFML_ENGINE_SOURCES})
target_include_directories (SFML-Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})