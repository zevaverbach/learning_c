#include <stdio.h>

int main(void) {
  int a[] = {[100] = 42};
  size_t size_of_a = sizeof(a);
  size_t size_of_item = sizeof(a[0]);
  printf("size of a in bytes: %zu\n", size_of_a);
  printf("size of a[0] in bytes: %zu\n", size_of_item);
  printf("number of items in a: %zu\n", size_of_a / size_of_item);
  return 0;
}
