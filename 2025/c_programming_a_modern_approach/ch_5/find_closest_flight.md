If it's 2am then the closest flight is 9:45pm, not 8:00am because
it's 4.25 hours between 9:45pm and 2am, versus six hours for the latter.

With the following implementation,

```c
int get_diff(int flight_time, int current_time) {
  int diff = flight_time - current_time;
  return diff < 0 ? -diff : diff;
}
```

When `current_time` is 120 and `flight_time` is 8:00am -> 480, the difference is 360.

When `current_time` is 120 and `flight_time` is 9:45pm -> 1_305, the difference is 1_185, but what we'd like it to show is 255.
