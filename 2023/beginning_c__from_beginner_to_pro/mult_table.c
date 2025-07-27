#include <stdio.h>
#include <sys/_types/_size_t.h>

/* Write a program that will generate a multiplication table of a size entered by the user. 
A table of size 4, for instance, would have four rows and four columns. 
The rows and columns would be labeled from 1 to 4. 
Each cell in the table will contain the product of the corresponding row and column numbers, 
so the value in the position corresponding to the third row and the fourth column would contain 12.*/

void print_column_labels(int size_of_table) {
    printf("   ");
    for (int i=0; i<size_of_table; i++) {
        printf("%d  ", i + 1);
    }
    printf("\n");
}

int main(void)
{
    unsigned int size_of_table;
    printf("How large of a multiplication table would you like?\n");
    scanf("%d", &size_of_table);
    print_column_labels(size_of_table);
    unsigned int prev_prod = 0;
    unsigned int prod = 0;
    for (unsigned int i=0; i<size_of_table; i++) {
        for (unsigned int j=0; j<size_of_table; j++) {
            if (j == 0) {
                printf("%d", i + 1);
            }
            prod = (i + 1) * (j + 1);
            if (prev_prod > 99) {
                printf("%d");
            } else if (prev_prod > 9) {
                printf(" %d", prod);
            } else {
                printf("  %d", prod);
            }
            prev_prod = prod;
        }
        printf("\n");
        prev_prod = 0;
    }
    return 0;
}

