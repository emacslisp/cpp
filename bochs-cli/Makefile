LIBDIRS = -L /usr/local/lib
INCDIRS = -I /usr/include -I /usr/local/include/GL -I ../../../../src/shared -I/usr/include/GL

CC = gcc
CFLAGS = -gdwarf-2 -g3
LIBS = -lm

All: bochs-cli

.c.o:
	$(CC) -c $(CFLAGS) $*.cpp

bochs-cli:
	$(CC) $(CFLAGS) -o bochs-cli $(LIBDIRS) main.cpp $(LIBDIRS)

clean:
	rm -f *.o
