#include <stdio.h>

int main(void) {
  printf("to what precision shall we calculate 'e'? " );
  int n;
  scanf("%d", &n);
  float e = 1;
  for (int i = 1; i < n; i++) {
    float prod = 1;
    for (int j = i; j > 1; j--) {
      prod *= j;
    }
    e += 1 / prod;
  }
  printf("e is approximately %.22f\n", e);
  return 0;
}
