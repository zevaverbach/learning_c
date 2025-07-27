#include <stdio.h>

typedef short Int8;
typedef int Int16;
typedef long Int32;

int main(void) {
  Int32 a = 32000000000;
  Int16 b = 5;
  printf("a - b -> %ld\n", a - b);
  return 0;
}
