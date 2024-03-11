OBJS = main.cpp Movable.o AutoMovable.o GameScreen.o MenuScreen.o TitleScreen.o Screen.o HighScoreScreen.o Camera.o LevelEditor.o Helper.o
CC = g++

CCFLAGS = -std=c++11 -Wall -Wextra -Wpedantic -O2

LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm 

OBJ_NAME = main

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)


Camera.o: Camera.cpp
	$(CC) -c Camera.cpp $(CCFLAGS)
Movable.o: Movable.cpp
	$(CC) -c Movable.cpp $(CCFLAGS) 
AutoMovable.o: AutoMovable.cpp
	$(CC) -c AutoMovable.cpp $(CCFLAGS) 
Screen.o: Screen.cpp
	$(CC) -c Screen.cpp $(CCFLAGS) 
GameScreen.o: GameScreen.cpp
	$(CC) -c GameScreen.cpp $(CCFLAGS) 
MenuScreen.o: MenuScreen.cpp
	$(CC) -c MenuScreen.cpp $(CCFLAGS) 
TitleScreen.o: TitleScreen.cpp
	$(CC) -c TitleScreen.cpp $(CCFLAGS) 
HighScoreScreen.o: HighScoreScreen.cpp
	$(CC) -c HighScoreScreen.cpp $(CCFLAGS)
LevelEditor.o: LevelEditor.cpp
	$(CC) -c LevelEditor.cpp $(CCFLAGS)
Helper.o: Helper.cpp
	$(CC) -c Helper.cpp $(CCFLAGS)

clean : 
	rm main *.o *~
