#include <stdio.h>

int main(void) {
  float f, frac_part;
  printf("enter a fraction: ");
  scanf("%f", &f);
  frac_part = f - (int) f;
  printf("frac_part: %f\n", frac_part);
  return 0;
}
