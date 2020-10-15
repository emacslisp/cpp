LIBDIRS = -L /usr/local/lib -L.
INCDIRS = -I /usr/include -I /usr/local/include/GL -I ../../../../src/shared -I/usr/include/GL

CC = g++
CFLAGS = -gdwarf-2 -g3
LIBS = -lm

All: bochs-cli

crc.o:
	$(CC) -c $(CFLAGS) *.cc

bochs-cli: crc.o
	$(CC) $(CFLAGS) -o bochs-cli main.cpp *.o $(INCDIRS) $(LIBDIRS)

clean:
	rm -f *.o
