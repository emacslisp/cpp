LIBDIRS = -L /usr/local/lib
INCDIRS = -I /usr/include -I /usr/local/include/GL -I ../../../../src/shared -I/usr/include/GL

CC = gcc
CFLAGS = -gdwarf-2 -g3
LIBS = -lm

All: Block

.c.o:
        $(CC) -c $(CFLAGS) $*.cpp

clib:
        $(CC) $(CFLAGS) -o Block $(LIBDIRS) Block.cpp $LIBDIRS

clean:
        rm -f *.o
