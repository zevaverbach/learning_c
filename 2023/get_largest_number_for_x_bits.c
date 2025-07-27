#include <stdio.h>
#include <stdint.h>

int main()
{
  uint64_t zero = 0;
  uint64_t minus_one = zero - 1;
  printf("%llu", minus_one);
  return 0;
}
