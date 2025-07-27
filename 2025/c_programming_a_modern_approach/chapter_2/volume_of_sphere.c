#include <stdio.h>

/*
  Write a program which computes the volume of a sphere with a 10-meter radius
  using the formula

      v = 4/3 * π * r^3
*/
int main(void) {
  float r;
  printf("what is the radius of your sphere?\n\n");
  scanf("%f", &r);
  float pi = 3.14;
  float v = pi * r * r * r * 4 / 3;
  printf("\nthe volume of a sphere with radius %.2f is %.2f\n", r, v);
}
