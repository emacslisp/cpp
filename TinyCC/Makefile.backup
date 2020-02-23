LIBDIRS = -L /usr/local/lib
INCDIRS = -I /usr/include -I /usr/local/include/GL -I ../../../../src/shared -I/usr/include/GL

CC = gcc
CFLAGS = -gdwarf-2 -g3
LIBS = -lglut -lGL -lGLU -lm

All: Block

build:
	$(CC) -c $(CFLAGS) *.c

Block: build
	$(CC) $(CFLAGS) -o tinycc $(LIBDIRS) *.o

clean:
	rm -f *.o
	rm -f tinycc
