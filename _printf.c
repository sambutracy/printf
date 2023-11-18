#include "main.h"

/**
 * _printf - Printf custom function implementation
 * @format: format.
 *
 * Author: Derrick Mungai
 *	Tracy Sambu
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    unsigned int i, sum_char = 0, found;
    va_list type;

    check fmat[] = {
        {"c", printfchar}, {"s", printstr}, {"%", printfpercentage},
        {"i", p_int},{"d",p_int},{"r", rev_function},{"R",rot13_funct}
    };

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    va_start(type, format);

    while (*format)
    {
        if (*format != '%' && *format != '\0')
        {
            _putchar(*format);
            sum_char++;
        }
        else
        {
            format++;

            if (*format == '\0')
                break;

            for (found = 0, i = 0; i < sizeof(fmat) / sizeof(fmat[0]); i++)
            {
                if (*format == *(fmat[i].lett)||(*format == 'd' && *(fmat[i].lett) == 'i'))
                {
                    sum_char += fmat[i].func(type);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                _putchar(*(--format));
                sum_char++;
            }
        }
        format++;
    }

    va_end(type);
    return (sum_char);
}
