#include <stdio.h>
#define MESSAGE_WITH_A_LENGTH_GREATER_THAN_31_HOPEFULLY "Hi Mom!\n"

int main(void)
{
    int a_number_whose_var_name_has_quite_a_long_length_wouldnt_you_say = 42;
    printf(MESSAGE_WITH_A_LENGTH_GREATER_THAN_31_HOPEFULLY);
    printf("%d\n", a_number_whose_var_name_has_quite_a_long_length_wouldnt_you_say);
    return 0;
}
