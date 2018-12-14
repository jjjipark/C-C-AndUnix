SOURCES = power.c factorial.c main.c
HEADERS = power.h factorial.h
OBJECTS = $(SOURCES:.c=.o)

LIBS = -lm

CC = gcc
CFLAGS = -std=c11 -g -Wall


%.o: %.c %.h
	$(CC) -c $(CFLAGS) $<

main: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LIBS)

power: power.o
	$(CC) -o $@ power.o $(LIBS)

factorial: factorial.o
	$(CC) -o $@ factorial.o $(LIBS)

libpower.a: power.o factorial.o
	ar  rcs libmean.a power.o facotiral.o main.o


