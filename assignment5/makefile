CXX = g++
CFLAGS = -std=c++14 -g -Wall

%.o : %.cpp
	$(CXX) -c $(CFLAGS) $< 

all: test-game.exe

test-game.exe: test-game.o game.o
	$(CXX) -o $@ test-game.o game.o

clean:
	$(RM) test-game.exe test-game.o game.o $(OBJECTS)

