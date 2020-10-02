CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
CFLAGS+= \
					-I./inc
SOURCES=src/*.c
EXE=main

all: main


main: main.c $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $(EXE)

clean:
	rm $(EXE)