#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

int main(int argc, char *argv[])
{
  size_t page_size = getpagesize();
  printf("page size: %d\n", getpagesize());
  return 0;
}

