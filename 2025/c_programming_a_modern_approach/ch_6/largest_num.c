#include <stdio.h>

#define PROMPT "Enter a number: "

int main(void) {
  float num = 0;
  float largest_num = num;
  do {
    printf(PROMPT);
    scanf("%f", &num);
    if (num > largest_num) {
      largest_num = num;
    }
  } while (num > 0);
  printf("The largest number entered was %f\n", largest_num);
}
