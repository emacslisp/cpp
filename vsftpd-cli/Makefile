LIBDIRS = -L /usr/local/lib
INCDIRS = -I /usr/include 

CC = gcc
CFLAGS = -gdwarf-2 -g3
LIBS = -lglut -lGL -lGLU -lm

All: Cat

.c.o:
	$(CC) -c $(CFLAGS) $*.cpp

Cat:
	$(CC) $(CFLAGS) -o postlogin $(LIBDIRS) postlogin.c $(LIBDIRS)

clean:
	rm -f *.o
	rm cat
	rm *~
