
/*
  Write a program that asks the user to enter a dollar amount
  and then shows how to pay that amount using the smallest number of
  20, 10, 5 and 1-denominated bills.
*/

#include <stdio.h>
#include <math.h>

int main(void) {
  float amount = 1011;
  // printf("Enter a dollar amount: ");
  // scanf("%f", &amount);

  float num_20s = floor(amount / 20);
  amount -= num_20s * 20;

  float num_10s = floor(amount / 10);
  amount -= num_10s * 10;

  float num_5s = floor(amount / 5);
  amount -= num_5s * 5;

  int num_1s = amount;

  printf("$20 bills: %.0f\n", num_20s);
  printf("$10 bills: %.0f\n", num_10s);
  printf("$5 bills: %.0f\n", num_5s);
  printf("$1 bills: %d\n", num_1s);

}
