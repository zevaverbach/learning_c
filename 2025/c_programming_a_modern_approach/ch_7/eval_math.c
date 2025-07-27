#include <stdio.h>
#include <stdbool.h>

/*
  Write a program that evaluates an expression e.g.

      Enter an expression: 1+2.5*3
      Value of expression: 10.5

*/

int main(void) {
  float total, rhs;
  char operator;
  printf("Enter an expression: ");
  scanf("%f", &total);
  while (true) {
    scanf("%c", &operator);
    if (operator == '\n') {
      break;
    }
    scanf("%f", &rhs);

    if (operator == '+') {
      total += rhs;
    } else if (operator == '-') {
      total -= rhs;
    } else if (operator == '*') {
      total *= rhs;
    } else {
      total /= rhs;
    }
  }
  printf("Value of expression: %.1f\n", total);
  return 0;
}
