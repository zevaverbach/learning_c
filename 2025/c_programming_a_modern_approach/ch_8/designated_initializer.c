#include <stdio.h>

int main(void) {
  int a[] = {[100] = 42};
  printf("a[0] = %d\n", a[0]);
  printf("a[99] = %d\n", a[99]);
  printf("a[100] = %d\n", a[100]);
  return 0;
}
