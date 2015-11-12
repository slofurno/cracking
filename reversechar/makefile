flags=-std=c11 -Wall -Wextra

all: test

test: build
	./reverse "thank_you_windows"

reverse.o: reverse.c
	gcc $(flags) -c reverse.c

build: reverse.o
	gcc $(flags) reverse.o -o reverse

clean:
	rm *.o
