#include <stdio.h>

int main(void) {
  // fill an array with the first 40 numbers in the Fibonacci sequence
  size_t fib_seq[40] = { 1, 1 };
  for (size_t i = 0; i < 39; i++) {
    fib_seq[i + 2] = fib_seq[i] + fib_seq[i + 1]; 
  }
  for (size_t i = 0; i <= 39; i++) {
    printf("%zu (%zu) \n", fib_seq[i], i + 1);
  }

  return 0;
}
