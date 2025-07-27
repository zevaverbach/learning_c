#include <stdio.h>
#include <math.h>

int get_num_digits(int num)
{
  int the_log_10 = log10(num);
  printf("\nlog10 of %d is %d\n", num, the_log_10);
  int num_digits = floor(the_log_10 + 1);
  return num_digits;
}

int main()
{
  int the_num = 42000;
  int num_digits = get_num_digits(the_num);
  printf("%d has %d digits\n\n", the_num, num_digits);
  return 0;
}
