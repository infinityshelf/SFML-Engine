CFLAGS = -std=c++14 -Wall -Winit-self -Wextra -pedantic -Wredundant-decls -Wcast-align -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Winvalid-pch -flto -Wodr -Wformat=2 -Wmissing-format-attribute -Wformat-nonliteral
#CFLAGS = -std=c++14 -Wall -Winit-self -Wextra -pedantic -Wredundant-decls -Wcast-align -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Winvalid-pch -flto -Wodr -Wformat=2 -Wmissing-format-attribute -Wformat-nonliteral -Werror
PROJECT = SFML-Engine

all:
	make run

run: $(PROJECT)
	./$(PROJECT) $(PROJECT)

$(PROJECT): main.o World.o
	g++ $(CFLAGS) main.o World.o -o $(PROJECT) -lsfml-window -lsfml-system -lsfml-graphics

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

World.o: World/World.cpp World/World.hpp
	g++ $(CFLAGS) -c World/World.cpp

clean:
	rm *.o
	rm $(PROJECT)

recompile:
	make clean
	make $(PROJECT)
