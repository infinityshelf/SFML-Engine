# SFML-Engine
SFML Engine. Component based, variable time step

You will need the SFML libraries.
To use this project, you will have to add this as a submodule to a project.
and have the following in your CMakeLists.txt:
```
add_subdirectory(SFML-Engine)

target_link_libraries(ExampleExecutable LINK_PUBLIC SFML-Engine -lsfml-graphics -lsfml-window -lsfml-system)
```

You can find an example in the SFML-Engine-Demo repository.
