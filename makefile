CC=g++
STD=-std=c++17
CFLAGS=-Wall
INC_PATH=$(shell find ./libs -type d -exec echo -I{} \;)
SRC=src/main.cpp src/game/game.cpp src/utils/configuration.cpp src/ECS/ECS.cpp src/assets_manager/assets_manager.cpp
LFLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua5.3
EXEC=pseudo_motor

build:
	$(CC) $(CFLAGS) $(STD) $(INC_PATH) $(SRC) $(LFLAGS) -o $(EXEC)

run:
	./$(EXEC)

clean:
	rm $(EXEC)