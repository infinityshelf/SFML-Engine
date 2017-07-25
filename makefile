#CFLAGS = -std=c++14 -Wall -Winit-self -Wextra -pedantic -Wredundant-decls -Wcast-align -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Winvalid-pch -flto -Wodr -Wformat=2 -Wmissing-format-attribute -Wformat-nonliteral
CFLAGS = -std=c++14 -Wall -Winit-self -Wextra -pedantic -Wredundant-decls -Wcast-align -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Winvalid-pch -flto -Wodr -Wformat=2 -Wmissing-format-attribute -Wformat-nonliteral -Werror
PROJECT = SFML-Engine

all:
	make run

run: $(PROJECT)
	./$(PROJECT) $(PROJECT)

$(PROJECT): main.o World.o Player.o Input.o
	g++ $(CFLAGS) main.o World.o Player.o Input.o -o $(PROJECT) -lsfml-window -lsfml-system -lsfml-graphics

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

World.o: World/World.cpp World/World.hpp
	g++ $(CFLAGS) -c World/World.cpp

Player.o: Player/Player.hpp Player/Player.cpp Entity.hpp
	g++ $(CFLAGS) -c Player/Player.cpp

Input.o: Input/Input.cpp Input/Input.hpp Input/InputListener.hpp Input/InputStruct.hpp
	g++ $(CFLAGS) -c Input/Input.cpp	

clean:
	rm *.o
	rm $(PROJECT)

recompile:
	make clean
	make $(PROJECT)
