#include "main.h"

/**
 * handle_print - to print an argument depending on type
 * @frmt: Formatted string to print arguments.
 * @lst: List of arguments to be printed.
 * @ind: Index.
 * @b: Buffer array.
 * @flag_: Calculate active flags.
 * @w: Get width.
 * @precision: Precision specification.
 * @s: Size specifier.
 * Return: 1 or 2;
 */
int handle_print(const char *frmt, int *ind, va_list lst, char b[],
                 int flag_, int w, int precision, int s)
{
    int i, unknown_len = 0, printed_chars = -1;
    frmt_t fmt_types[] = {
        {'c', printfchar}, {'s', printstr}, {'%', printfpercent},
        {'i', p_int}, {'d', p_int}, {'b', p_binary},
        {'u', p_unsigned}, {'o', p_octal}, {'x', p_hexadec},
        {'X', p_hex_upper}, {'p', p_pointer}, {'S', p_non_printable},
        {'r', p_reverse}, {'R', p_rot13string}, {'\0', NULL},
        {'u', p_unsigned}, {'o', p_octal}, {'x', p_hexadec},
        {'X', p_hex_upper}, {'p', p_pointer}, {'r', p_reverse},
        {'R', p_rot13string}, {'\0', NULL}
    };

    for (i = 0; fmt_types[i].frmt != '\0'; i++)
    {
        if (frmt[*ind] == fmt_types[i].frmt)
            return (fmt_types[i].fmt_t(lst, b, flag_, w, precision, s));
    }

    if (fmt_types[i].frmt == '\0')
    {
        if (frmt[*ind] == '\0')
            return (-1);

        unknown_len += write(1, "%%", 1);

        if (frmt[*ind - 1] == ' ')
            unknown_len += write(1, " ", 1);
        else if (w)
        {
            --(*ind);
            while (frmt[*ind] != ' ' && frmt[*ind] != '%')
                --(*ind);

            if (frmt[*ind] == ' ')
                --(*ind);

            return (1);
        }

        unknown_len += write(1, &frmt[*ind], 1);
        return (unknown_len);
    }

    return (printed_chars);
}

