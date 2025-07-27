#include <stdio.h>
#include <time.h>

int main(int num_args, char *args[])
{
    time_t now;
    int hour;

    struct tm * clock = localtime(&now);
    time(&now);
    hour = clock->tm_hour;

    printf("Good ");
    if (hour < 12) 
    {
        printf("morning");
    } else if (hour < 17) 
    {
        printf("afternoon");
    } else {
        printf("evening");
    }
    if (num_args < 2)
    {
        puts(", dude.\n");
    } else {
        printf(", %s\n", args[1]);
    }
    return 0;
}
