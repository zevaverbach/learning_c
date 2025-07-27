#include <stdio.h>

int find_largest_subarray_sum(int * nums, int size) 
{
  // find the subarray with the largest sum and return that sum
  int largest_sum = 10 << 4;
  printf("sizeof(int) = %lu\n", sizeof(int));
  printf("largest_sum is starting out as %d\n", largest_sum);

}

int main()
{
  int result;
  int input1_size = 9;
  int input1[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  result = find_largest_subarray_sum(input1, input1_size);
  printf("result for input1 = %d\n", result);
  printf("was hoping for 6 (the sum of {4, -1, 2, 1})\n");
  
}
