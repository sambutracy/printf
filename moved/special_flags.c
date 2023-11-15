#include "main.h"

/**
 * specialflags - Calculates active flags
 * @string: Formatted string to print the arguments
 * @x: Parameter index.
 * Return: Flags
 */

int specialflags(const char *string, int *x)
{
    /* - + 0 # ' ' */
    /* 1 2 4 8  16 */
    int j, current_index;
    int f = 0;
    const char charflag[] = {'-', '+', '0', '#', ' ', '\0'};
    const int intdescription[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    for (current_index = *x + 1; string[current_index] != '\0'; current_index++)
    {
        j = 0;
        while (charflag[j] != '\0')
        {
            if (string[current_index] == charflag[j])
            {
                f |= intdescription[j];
                break;
            }
            j++;
        }

        if (charflag[j] == 0)
            break;
    }

    *x = current_index - 1;

    return (f);
}
