flags=-std=c11 -Wall -Wextra

all: test

test: build
	./quicksort

quicksort.o: quicksort.c
	gcc $(flags) -c quicksort.c

build: quicksort.o
	gcc $(flags) quicksort.o -o quicksort

clean:
	rm *.o
