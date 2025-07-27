/*
  Write a program which takes a first and last name entered by the user and displays the last name, first initial like "Smith, J."
*/

#include <stdio.h>

int main(void) {
  char first_char, last_entered_char;
  // skip leading spaces
  while ((first_char = getchar()) == ' ');
  // skip first word after the first letter
  while ((last_entered_char = getchar()) != ' ');

  while ((last_entered_char = getchar()) != '\n') {
    printf("%c", last_entered_char);
  }
  printf(", %c.\n", first_char);
  return 0;
}
