#include <stdio.h>
#include <string.h>

int main()
{
  int x;
  int *px;
  x = 42;
  px = &x;
  long px_copy;
  px_copy = px;
  printf("x = %d\n", x);
  printf("px = %p\n", px);
  printf("px_copy = %ld\n", px_copy);
  printf("*px = %d\n", *px);
  printf("incremented");
  x++;
  printf("x = %d\n", x);
  printf("px = %p\n", px);
  printf("*px = %d\n", *px);
  return 0;
}

