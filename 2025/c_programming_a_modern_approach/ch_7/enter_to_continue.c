#include <stdio.h>
#include <stdbool.h>

#define ENTER_KEY_NUM 10;

int main(void) {
  int i = 1;
  while (true) {
    if (i % 1000000 == 0) {
      printf("press ENTER to continue...");
      while (getchar() != 10) {
        continue;
      }
    }
    printf("%d\n", i);
    i++;
  }
  return 0;
}
