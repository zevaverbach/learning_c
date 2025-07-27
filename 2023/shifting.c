#include <stdint.h>
#include <stdio.h>

int main()
{
  uint64_t one = 1;
  uint64_t sixteen_times = one << 16; // this is hopefully 65_536 or so
  uint64_t thirty_two_times = one << 32; // this is hopefully 65_536 or so
  printf("\n%llu", sixteen_times);
  printf("\n%llu\n", thirty_two_times);
}
