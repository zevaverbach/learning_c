#include <stdio.h>

int main(void) {
  char c = '\1';
  short s = 2;
  int i = -3;
  long m = 5;
  float f = 6.5f;
  double d = 7.5;

  printf("c is %d\n", c);
  printf("i is %d\n", i);
  printf("c * i = %d\n", c * i);

  printf("s is %d\n", c);
  printf("m is %d\n", i);
  printf("s + m = %d\n", c + i);

  printf("f is %f\n", f);
  printf("c is %d\n", c);
  printf("f / c = %f\n", f / c);

  printf("d is %f\n", d);
  printf("s is %d\n", s);
  printf("d / s = %lf\n", d / s);

  printf("f is %f\n", f);
  printf("d is %lf\n", d);
  printf("f - d = %lf\n", f - d);

  printf("f is %f\n", f);
  printf("(int) f = %d\n", (int) f);

  return 0;
}
