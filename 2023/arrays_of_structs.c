#include <stdio.h>
#include <stdlib.h>

typedef struct MyStruct {
    char name[10];
} MyStruct;


int main()
{
    MyStruct * structs_p = malloc(5 * sizeof(MyStruct));
    MyStruct &structs_p[0] = { "Sylvia" };
    printf("structs[4] = '%s'\n", structs[4].name);
    printf("pointer for structs[4] = '%p'\n", &structs[4].name);
    return 0;
}
