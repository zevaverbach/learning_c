#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

int generate_random_num(void) {
  srand(time(NULL)); // seed rand
  return rand() % MAX_NUM + 1;
}

int main(void)
{
  int random_num = generate_random_num();
  int guess = 0;
  char* high_or_low = "";
  printf("randomNum: %d\n", random_num);
  while (guess != random_num) {
    printf("guess?\n> ");
    scanf("%d", &guess);

    /*  TODO: an interesting bug is that if I hit <C-d> at this moment it goes 
              into an infinite loop of printing this prompt over and over without taking
              any input. The same thing happens if you give it a float as the input 
              instead of an int!  These loops are only terminated with <C-c> */
    if (guess > random_num) {
      high_or_low = "high";
    } else {
      high_or_low = "low";
    }
    printf("guess is %s\n", high_or_low); 
  }
  printf("you got it!\n");
  exit(0);
}
