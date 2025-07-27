#include <stdio.h>
#include <stdbool.h>

int main(void) {
  bool bools[100] = {false};
  bool multi_dimensional_bools[3][5] = {false};
  for (size_t i = 0; i < 100; i++) {
    printf("bools[%zu] => %b\n", i, bools[i]);
  }
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 5; j++) {
      printf("multi_dimensional_bools[%zu][%zu] => %b\n", i, j, multi_dimensional_bools[i][j]);
    }
  }

  return 0;
}
