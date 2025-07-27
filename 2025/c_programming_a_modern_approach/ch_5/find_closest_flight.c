#include <stdio.h>

/*
  find the closest flight

  Departure Time      Arrival Time
     8:00am             10:16am
     9:43am             11:52am
    11:19am              1:31pm
    12:47pm              3:00pm
     2:00pm              4:08pm
     3:45pm              5:55pm
     7:00pm              9:20pm
     9:45pm             11:58pm
*/

int min(int num1, int num2) {
  return num1 < num2 ? num1 : num2;
}

int get_diff(int flight_time, int current_time) {
  int diff = flight_time - current_time;
  if (diff < 0) {
    diff = -diff;
  }
  int flight_time_to_midnight = (24 * 60) - flight_time;
  int mid_diff = flight_time_to_midnight + current_time;
  return min(mid_diff, diff);
}

int main(void) {
  printf("Enter a 24-hour time: ");
  int hours, minutes;
  scanf("%2d:%2d", &hours, &minutes);

  int minutes_since_midnight = minutes + (hours * 60);
  int smallest_diff = 60 * 24;
  int diff;

  char *departure_time;
  char *arrival_time;

  diff = get_diff(8 * 60, minutes_since_midnight);
  if (diff < smallest_diff) {
    smallest_diff = diff;
    departure_time = "8:00am";
    arrival_time = "10:16am";
  }

  diff = get_diff((9 * 60) + 43, minutes_since_midnight);
  if (diff < smallest_diff) {
    smallest_diff = diff;
    departure_time = "9:43am";
    arrival_time = "11:52am";
  }

  diff = get_diff((11 * 60) + 19, minutes_since_midnight);
  if (diff < smallest_diff) {
    smallest_diff = diff;
    departure_time = "11:19am";
    arrival_time = "1:31pm";
  }

  diff = get_diff((12 * 60) + 47, minutes_since_midnight);
  if (diff < smallest_diff) {
    smallest_diff = diff;
    departure_time = "12:47pm";
    arrival_time = "3:00pm";
  }

  diff = get_diff((14 * 60), minutes_since_midnight);
  if (diff < smallest_diff) {
    smallest_diff = diff;
    departure_time = "2:00pm";
    arrival_time = "4:08pm";
  }

  diff = get_diff((15 * 60) + 45, minutes_since_midnight);
  if (diff < smallest_diff) {
    smallest_diff = diff;
    departure_time = "3:45pm";
    arrival_time = "5:55pm";
  }

  diff = get_diff((19 * 60), minutes_since_midnight);
  if (diff < smallest_diff) {
    smallest_diff = diff;
    departure_time = "7:00pm";
    arrival_time = "9:20pm";
  }

  diff = get_diff((21 * 60) + 45, minutes_since_midnight);
  if (diff < smallest_diff) {
    smallest_diff = diff;
    departure_time = "9:45pm";
    arrival_time = "11:58pm";
  }

  printf("Closest departure time is %s, arriving at %s\n", departure_time, arrival_time);
  return 0;
}
