CFLAGS = -std=c++14 -Wall -Winit-self -Wextra -pedantic -Wredundant-decls -Wcast-align -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Winvalid-pch -flto -Wodr -Wformat=2 -Wmissing-format-attribute -Wformat-nonliteral

all:
	make libSFML-Engine.a

EntityManager.o: EntityManager.cpp EntityManager.hpp
	g++ $(CFLAGS) -c EntityManager.cpp

GraphicsComponent.o: GraphicsComponent.cpp GraphicsComponent.hpp
	g++ $(CFLAGS) -c GraphicsComponent.cpp

Input.o: Input.cpp Input.hpp
	g++ $(CFLAGS) -c Input.cpp

CollidableManager.o: CollidableManager.cpp CollidableManager.hpp
	g++ $(CFLAGS) -c CollidableManager.cpp

Component.o: Component.hpp Component.cpp
	g++ $(CFLAGS) -c Component.cpp

TextureManager.o: TextureManager.cpp TextureManager.hpp
	g++ $(CFLAGS) -c TextureManager.cpp

World.o: World.cpp World.hpp
	g++ $(CFLAGS) -c World.cpp

libSFML-Engine.a: Input.o EntityManager.o GraphicsComponent.o TextureManager.o World.o CollidableManager.o Component.o
	ar rcs libSFML-Engine.a Input.o EntityManager.o GraphicsComponent.o TextureManager.o World.o CollidableManager.o Component.o

libs: libSFML-Engine.a

clean:
	rm *.o
	rm *.a
	rm *.gch
	rm libSFML-Engine.a
