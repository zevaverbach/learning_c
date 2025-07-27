#include <stdio.h>

int main(void) {
  int n;
  printf("enter an integer and I'll print all the even squares between zero and it: ");
  scanf("%d", &n);
  int i, product;
  for (i = 1, product = i * i; i <= n / 10, product % 2 == 0; i++, product = i * i) {
    printf("%d\n", i * i);
  }
  return 0;
  }
