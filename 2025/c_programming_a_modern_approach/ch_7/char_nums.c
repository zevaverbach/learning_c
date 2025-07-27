#include <stdio.h>
#include <stdbool.h>

#define ENTER_KEY_NUM 10;

int main(void) {
  while (true) {
    char c = getchar();
    printf("you typed '%d'\n", c);
  }
  return 0;
}
