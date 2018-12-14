SOURCES = maze.c move_maze.c
HEADERS = move_maze.h
OBJECTS = $(SOURCES:.c=.o)
LIBS = -lm

maze:
		gcc -o maze -std=c11 maze.c move_maze.c

clean: 
		$(RM) maze $(OBJECTS)
