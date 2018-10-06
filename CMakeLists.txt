set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/Program Files\ (x86)/SFML/lib/cmake/SFML")

include_directories("C:\\Program Files\ (x86)\\SFML\\include")
find_package(SFML 2.5 REQUIRED graphics window network audio system )

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
        CollidableManager.hpp
        FSM.hpp
        FSM.cpp)

add_library(SFML-Engine ${SFML_ENGINE_SOURCES})
target_include_directories (SFML-Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(SFML-Engine sfml-window sfml-graphics sfml-system)