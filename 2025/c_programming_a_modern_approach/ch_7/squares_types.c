#include <stdio.h>
/*
  This is interesting. The compiler and linter give me warnings about implicit conversion to `long` when I assign a value to `n` above ~2_147_400_000. Meanwhile, if I stay at or below that value the results are as expected. However, somewhere above 2146923072 the sign flips:

      i (46340) * i (46340) = 2147395600
      breaking becauses we're about to overflow

  This happens because, indeed, `i * i` _is_ less than `n`, but only because there's been an overflow.

  The exact highest number for `short` is 2_147_483_647

  What's also interesting is that I get a compilation warning if I assign a value one larger than the largest int, even if I use the type `long` or `long long` for `n`.

  I conclude that the number of bits my machine uses to store an `int` is 32 bits: one bit for the sign, and 31 bits for the number:

  2^31 = 2_147_483_648

*/

#define LARGEST_INT 2147483647
#define LARGEST_SHORT 32767

int main(void) {
  long long n = LARGEST_INT + 1;
  for (int i = 1; (i * i) < n; i++) {
    if (i * i < 0) {
      printf("breaking becauses we're about to overflow\n");
      printf("the next product is %d x %d = %d\n", i, i, i * i);
      break;
    }
    if (i * i <= n) {
      printf("i (%d) * i (%d) = %d\n", i, i, i * i);
    }
  }
  return 0;
}
