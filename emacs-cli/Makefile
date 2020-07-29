LIBDIRS = -L /usr/local/lib
INCDIRS = -I /usr/include -I /usr/local/include/GL -I ../../../../src/shared -I/usr/include/GL

CC = gcc
CFLAGS = -gdwarf-2 -g3
LIBS = -lglut -lGL -lGLU -lm

All: Main

.c.o:
        $(CC) -c $(CFLAGS) $*.c

Main:
        $(CC) $(CFLAGS) -o emacs $(LIBDIRS)

clean:
        rm -f *.o
