#include <stdio.h>
#include <stdbool.h>
/*
  Write a program that calculates the average word length for a sentence:

      Enter a sentence: It was deja vu all over again.
      Average word length: 3.4
*/

int main(void) {
  printf("Enter a sentence: ");
  float num_words = 0;
  float num_chars = 0;
  char next_char;
  while ((next_char = getchar()) != '\n') {
    if (next_char == ' ') {
      num_words++;
    } else {
      num_chars++;
    }
  }
  num_words++; // when the next char is '\n' we've finished one more word
  printf("Average word length: %.1f\n", num_chars / num_words);
  return 0;
}
