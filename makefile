#CFLAGS = -std=c++14 -Wall -Winit-self -Wextra -pedantic -Wredundant-decls -Wcast-align -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Winvalid-pch -flto -Wodr -Wformat=2 -Wmissing-format-attribute -Wformat-nonliteral
CFLAGS = -std=c++14 -Wall -Winit-self -Wextra -pedantic -Wredundant-decls -Wcast-align -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Winvalid-pch -flto -Wodr -Wformat=2 -Wmissing-format-attribute -Wformat-nonliteral
PROJECT = SFML-Engine

all:
	make run

run: $(PROJECT)
	./$(PROJECT) $(PROJECT)

$(PROJECT): main.o World.o Player.o Input.o Component.o PlayerInputComponent.o PlayerGraphicsComponent.o TextureManager.o PlayerPhysicsComponent.o GraphicsComponent.o
	g++ $(CFLAGS) main.o World.o Player.o Input.o Component.o PlayerInputComponent.o PlayerGraphicsComponent.o TextureManager.o PlayerPhysicsComponent.o GraphicsComponent.o -o $(PROJECT) -lsfml-window -lsfml-system -lsfml-graphics

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

World.o: World.cpp World.hpp
	g++ $(CFLAGS) -c World.cpp

Player.o: Player.hpp Player.cpp Entity.hpp
	g++ $(CFLAGS) -c Player.cpp

Input.o: Input.cpp Input.hpp InputStruct.hpp
	g++ $(CFLAGS) -c Input.cpp

PlayerInputComponent.o: PlayerInputComponent.cpp PlayerInputComponent.hpp InputComponent.hpp Input.cpp Input.hpp InputStruct.hpp Component.o
	g++ $(CFLAGS) -c PlayerInputComponent.cpp

PlayerGraphicsComponent.o: PlayerGraphicsComponent.cpp PlayerGraphicsComponent.hpp GraphicsComponent.hpp Component.o
	g++ $(CFLAGS) -c PlayerGraphicsComponent.cpp

PlayerPhysicsComponent.o: PlayerPhysicsComponent.cpp PlayerPhysicsComponent.hpp PhysicsComponent.hpp Component.o
	g++ $(CFLAGS) -c PlayerPhysicsComponent.cpp

TextureManager.o: TextureManager.cpp TextureManager.hpp
	g++ $(CFLAGS) -c TextureManager.cpp	

Component.o: Component.hpp Component.cpp
	g++ $(CFLAGS) -c Component.cpp

GraphicsComponent.o: GraphicsComponent.hpp GraphicsComponent.cpp Component.o
	g++ $(CFLAGS) -c GraphicsComponent.cpp

clean:
	rm *.o
	rm $(PROJECT)

recompile:
	make clean
	make $(PROJECT)
