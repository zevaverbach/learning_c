#include <stdio.h>

/* 
  write a program which accepts a date from the user
  in the form mm/dd/yyyy and then displays it in the form
  yyyymmdd
*/
int main(void) {
  int month, day, year;
  printf("month, day and year in the format mm/dd/yyyy please: ");
  scanf("%d/%d/%d", &month, &day, &year);
  printf("\n%d%02d%02d", year, month, day);
  return 0;
}
