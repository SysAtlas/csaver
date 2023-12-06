CFLAGS=-std=gnu20 -O2 -Wall -Wextra -Wpedantic -g
.PHONY: clean

all: csaver.o main.o csaverutil.o 
	gcc csaverutil.o csaver.o main.o -o csaver -L/usr/local/lib -l:libraylib.so.500 -lm
csaver.o: csaver.c
	gcc -c csaver.c
main.o: main.c
	gcc -c main.c
csaverutil.o: csaverutil.c
	gcc -c csaverutil.c
clean:
	rm *.o csaver
