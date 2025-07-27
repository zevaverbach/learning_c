#include <stdio.h>

char to_upper(char a_char) {
  if (a_char >= 97 && a_char <= 97 + 26) {
    return a_char - 32;
  }
  return a_char;
}

int main(void) {
  printf("give me a letter and I'll uppercase it: ");
  char letter;
  scanf("%c", &letter);
  letter = to_upper(letter);
  printf("here it is! %c\n", letter);
  return 0;
}
