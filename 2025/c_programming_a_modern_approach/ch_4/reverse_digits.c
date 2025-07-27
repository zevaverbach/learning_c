/* 
 write a program which asks the user to enter a two-digit number,
 then prints the number with its digits reversed.
*/

#include <stdio.h>

int using_math(void) {
  printf("enter a three digit number: ");
  int entry;
  scanf("%d", &entry);
  int first_digit = entry / 100;
  int last_digits = entry % 100;
  int second_digit = last_digits / 10;
  int third_digit = last_digits % 10;
  printf("reversed: %d%d%d\n", third_digit, second_digit, first_digit);
  return 0;
}

int using_scanf(void) {
  printf("enter a nine digit number: ");
  int first, second, third;
  scanf("%1d%1d%1d", &first, &second, &third);
  printf("reversed: %d%d%d\n", third, second, first);
  return 0;
}

int main(void) {
  using_scanf();
  return 0;
}
