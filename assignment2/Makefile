SOURCES = square.c triangle.c diamond.c test.c
HEADERS = square.h triangle.h diamond.h
OBJECTS = $(SOURCES:.c=.o)
LIBS = -lm

CC = gcc
CFLAGS = -std=c11 -g -Wall

# Pattern used in target and prerequisites
%.o: %.c %.h
	$(CC) -c $(CFLAGS) $<

all: test-square test-diamond test-triangle test_all

test_all: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LIBS)

#tests: test-square test-diamond test-triangle

test-square: square.o test-square.o
	$(CC) -o $@ square.o test-square.o $(LIBS)

test-diamond: diamond.o square.o test-diamond.o
	$(CC) -o $@ diamond.o square.o test-square.o $(LIBS)

test-triangle: triangle.o test-triangle.o
	$(CC) -o $@ triangle.o test-triangle.o $(LIBS)

test-main.exe: square.o triangle.o diamond.o main.o
	$(CC) -o $@ square.o triangle.o diamond.o main.o $(LIBS)

memcheck: test_all.exe
	valgrind --leak-check=yes --track-origins=yes test_all

clean:
	$(RM) *.o test_all test_diamond test_square test_triangle




# Following the example for test-square.exe, add targets below for the remaining 
# programs: test-triangle.exe, test-diamond.exe test-all.exe
# Be careful with spaces vs tabs -- make sure you have a TAB, not spaces before $(CC)

#memcheck: test-all.exe
#	valgrind --leak-check=yes --track-origins=yes test-all.exe

# To get rid of all compiler-generated binary files, run "make clean"
# #clean: 
#	$(RM) $(wildcard *.exe) $(wildcard *.o)
