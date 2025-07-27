// we did this in an earlier chapter but now want to do it for arbitrary numbers of digits

#include <stdio.h>

int main(void) {
  int num;
  printf("enter an integer of any length and I'll reverse the digits: ");
  scanf("%d", &num);
  int next_digit;
  while (num > 0) {
    next_digit = num - (num / 10 * 10);
    printf("%d", next_digit);
    num /= 10;
  }
  printf("\n");
  return 0;
}
