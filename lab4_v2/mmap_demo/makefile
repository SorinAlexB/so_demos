CC = gcc
CFLAGS = -Wall -Wextra -O2

all: map_writer map_reader

map_writer: map_writer.c
	$(CC) $(CFLAGS) -o map_writer map_writer.c

map_reader: map_reader.c
	$(CC) $(CFLAGS) -o map_reader map_reader.c

clean:
	rm -f map_writer map_reader hello.txt
