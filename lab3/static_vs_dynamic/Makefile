CC = gcc
LDFLAGS_STATIC = -static

.PHONEY: all main

all: main main_static

main: main.o

main_static: main.o
	$(CC) $(LDFLAGS_STATIC) -o $@ $^

main.o: main.c

clean:

	-rm -f main_static main
	-rm -f main.o
	-rm -f *~
