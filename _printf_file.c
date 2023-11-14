#include "main.h"

/**
 * buffer.p - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_i: Index at which to add the next char, represents the length.
 */
void buffer.p(char buffer[], int *buff_i);

/**
 * custom_printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    int x, p = 0, p_c = 0;
    int f, w, precision, size, buff_i = 0;
    va_list p_f_list;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(p_f_list, format);

    x = 0;
    while (format && format[x] != '\0')
    {
        if (format[x] != '%')
        {
            buffer[buff_i++] = format[x];
            if (buff_i == BUFF_SIZE)
                buffer.p(buffer, &buff_i);
            p_c++;
        }
        else
        {
            buffer.p(buffer, &buff_i);
            f = get_flags(format, &x);
            w = get_width(format, &x, p_f_list);
            precision = get_precision(format, &x, p_f_list);
            size = get_size(format, &x);
            ++x;
            p = handle_print(format, &x, p_f_list, buffer,
                             f, w, precision, size);
            if (p == -1)
                return (-1);
            p_c += p;
        }
        x++;
    }

    buffer.p(buffer, &buff_i);

    va_end(p_f_list);

    return (p_c);
}

/**
 * buffer.p - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_i: Index at which to add the next char, represents the length.
 */
void buffer.p(char buffer[], int *buff_i)
{
    if (*buff_i > 0)
        write(1, &buffer[0], *buff_i);

    *buff_i = 0;
}
