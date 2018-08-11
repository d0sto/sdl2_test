#OBJS specifies which files to compile as part of the project 
OBJS = *.cpp

CC=clang

COMPILER_FLAGS = -Wall -g -Ofast
LINKER_FLAGS = -lstdc++ -lSDL2 -lSDL2_image 
OBJ_NAME = game
all : $(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
