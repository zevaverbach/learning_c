#include <stdio.h>

int main(void) {
  // find the largest and smallest numbers; use no more than four "if"s
  
  int one, two, three, four;
  printf("please enter four integers: ");
  scanf("%d %d %d %d", &one, &two, &three, &four);

  int smallest = one;
  int largest = two;
  if (one > two) {
    smallest = two;
    largest = one;
  }

  int smallest2 = three;
  int largest2 = four;
  if (three > four) {
    smallest2 = four;
    largest2 = three;
  }

  if (smallest2 < smallest) {
    smallest = smallest2;
  }

  if (largest2 > largest) {
    largest = largest2;
  }

  printf("the smallest is %d and the largest is %d\n", smallest, largest);
}
