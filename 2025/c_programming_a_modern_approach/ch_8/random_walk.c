#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define NUM_STEPS 26
#define NUM_DIRECTIONS 4

int main(void) {
  srand((unsigned) time(NULL));
  int x = 0;
  int y = 0;
  int arr[10][10] = { 0 };

  size_t steps_taken = 1;
  arr[0][0] = 1;

  int direction;

  for (size_t i = 0; i < NUM_STEPS; i++) {
    while (true) {
      direction = rand() % NUM_DIRECTIONS;
      printf("%zu: direction: %d", steps_taken, direction);
      if (direction == LEFT && x != 0 && !arr[--x][y]) {
        x--;
        arr[x][y] = steps_taken;
        break;
      } else if (direction == RIGHT && x != 9 && !arr[++x][y]) {
        x++;
        arr[x][y] = steps_taken;
        break;
      } else if (direction == UP && y != 0 && !arr[x][--y]) {
        y--;
        arr[x][y] = steps_taken;
        break;
      } else if (direction == DOWN && y != 9 && !arr[x][++y]) {
        y++;
        arr[x][y] = steps_taken;
        break;
      }
    }
    steps_taken++;
  }
  int val;
  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 10; j++) {
      val = arr[i][j]; 
      if (val == 0) {
        printf(". ");
      } else {
        printf("%d", val);
      }
      if (j == 9) {
        printf("\n");
      }
    }
  }
  return 0;
}
