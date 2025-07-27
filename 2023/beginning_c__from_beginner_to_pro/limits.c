#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    printf("variables of type char store values from %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("variables of type unsigned char store values from 0 to %d\n", UCHAR_MAX);
    printf("variables of type short store values from %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("variables of type unsigned short store values from 0 to %d\n", USHRT_MAX);
    printf("variables of type int store values from %d to %d\n", INT_MIN, INT_MAX);
    printf("variables of type unsigned int store values from 0 to %d\n", UINT_MAX);
    printf("variables of type long store values from %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("variables of type unsigned long store values from 0 to %lu\n", ULONG_MAX);
    printf("variables of type long long store values from %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("variables of type unsigned long long store values from 0 to %llu\n", ULLONG_MAX);
    printf("\nthe size of the smallest positive non-zero value of type float is %.3e\n", FLT_MIN);
}
