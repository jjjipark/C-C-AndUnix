CXX = g++
CFLAGS = -std=c++14 -g -Wall

%.o : %.cpp
	$(CXX) -c $(CFLAGS) $< 

# Add any additional targets you may have here 


# Link with external main (on ix-dev only)
all: test-maze.exe test-main.exe


test-maze.exe: maze_test.o maze.o    #add your objects to this line
	$(CXX) -o $@ maze_test.o maze.o

test-main.exe: main.o maze.o utils.o
	$(CXX) -o $@ main.o maze.o utils.o
clean:
	$(RM) test-maze.exe maze_test.o maze.o test-main.exe $(OBJECTS)
