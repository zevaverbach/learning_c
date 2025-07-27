/* 
Write a program that will output the printable characters for character code values from 0 to 127.
Output each character code along with its symbol with two characters to a line.
Make sure the columns are aligned. 
(Hint: You can use the isgraph() function that’s declared in ctype.h to determine when a character is printable.)” 
*/

#include <ctype.h>
#include <stdio.h>

int main(void) {
    for (int i=0; i<128; i++) {
        if (isgraph(i)) {
            printf("%d: %c\n", i, i);
        } else {
            printf("%d: %c\n", i, toascii(i));
        }
    }
    return 0;
}
