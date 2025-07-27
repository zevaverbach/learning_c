#include <stdio.h>

/* 
  Write a program which calculates how many digits a number contains.
*/
int main(void) {
  int num;
  int num_digits = 1;
  printf("enter a number: ");
  scanf("%d", &num); 
  while (num > 9) {
    num /= 10; 
    num_digits++;
  }
  printf("number of digits: %d\n", num_digits);
  return 0;  
}
