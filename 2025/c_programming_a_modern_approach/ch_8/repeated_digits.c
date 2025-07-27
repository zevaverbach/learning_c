#include <stdio.h>
#include <stdbool.h>

#define PROMPT "Enter a number: "
#define RESPONSE "Repeated digit(s): "

int main(void) {
  printf(PROMPT);
  size_t number;
  size_t digit;
  scanf("%zu", &number);
  bool digits_seen[10] = { false };
  bool digits_repeated[10] = { false };

  do {
    digit = number % 10; 
    // printf("digit: %zu\n", digit);
    if (digits_seen[digit] == true && digits_repeated[digit] == false) {
        digits_repeated[digit] = true;
    } else {
      digits_seen[digit] = true;
    }
    number /= 10;
    // printf("%zu\n", number);
  } while (number > 0);
  printf(RESPONSE);
  for (size_t i = 0; i < 10; i++) {
    if (digits_repeated[i] == true) {
      printf("%zu ", i);
    }
  }

  return 0;
}
