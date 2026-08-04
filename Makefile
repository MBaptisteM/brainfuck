CC = gcc
CFLAGS = -Wall -Wextra -O2 -Ilib

all: brainfuck

brainfuck: brainfuck.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f brainfuck

.PHONY: all clean