LIBDIRS = -L /usr/local/lib
INCDIRS = -I /usr/include 

CC = gcc
CFLAGS = -gdwarf-2 -g3
LIBS = -lglut -lGL -lGLU -lm

All: vsftpd-cli

.c.o:
	$(CC) -c $(CFLAGS) $*.cpp

vsftpd-cli:
	$(CC) $(CFLAGS) -o ftp-cli $(LIBDIRS) *.c $(LIBDIRS)

clean:
	rm -f *.o
	rm ftp-cli