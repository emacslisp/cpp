LIBDIRS = -L /usr/local/lib
INCDIRS = -I /usr/include -I /usr/local/include/GL -I ../../../../src/shared -I/usr/include/GL

CC = gcc
CXX = g++
CFLAGS = -gdwarf-2 -g3
LIBS = -lglut -lGL -lGLU -lm

All: main

.c.o:
	$(CXX) -c $(CFLAGS) *.cpp

main: .c.o
	$(CXX) $(CFLAGS) -o main *.o

clean:
	rm -f *.o
