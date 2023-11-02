CFLAGS=-std=gnu20 -O2 -Wall -Wextra -Wpedantic

.PHONY: clean

all: csaver.o main.o 
	gcc csaver.o main.o -o csaver -L/usr/local/lib -l:libraylib.so.500 -lm
csaver.o: csaver.c
	gcc -c csaver.c
main.o: main.c
	gcc -c main.c
clean:
	rm *.o csaver
