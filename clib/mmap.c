#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
typedef struct
{
    int integer;
    char string[24];
} RECORD;

#define NRECORDS (100)
int main()
{
    RECORD record, *mapped;
    int i, f;
    FILE *fp;

    f = open("records.dat", O_RDWR);
    mapped = (RECORD *)mmap(0, NRECORDS * sizeof(record),
                            PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);
    mapped[43].integer = 243;
    sprintf(mapped[43].string, "RECORD-%d", mapped[43].integer);
    msync((void *)mapped, NRECORDS * sizeof(record), MS_ASYNC);
    munmap((void *)mapped, NRECORDS * sizeof(record));
    close(f);
    exit(0);
}