flags=-std=c11 -Wall -Wextra

all: test

test: build
	./reverse "fuck_you_windows"
	./reverse "fuck_you!"

reverse.o: reverse.c
	gcc $(flags) -c reverse.c

build: reverse.o
	gcc $(flags) reverse.o -o reverse
