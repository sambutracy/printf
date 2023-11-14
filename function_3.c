#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * unsigned_p - Prints an unsigned number
 * @p_f_list: List of arguments
 * @buffer_p: Buffer array to handle print
 * @flags: Calculates active flags
 * @w: Width specifier
 * @precision: Precision specification
 * @size_: Size specifier
 * Return: Number of characters printed.
 */
int unsigned_p(va_list p_f_list, char buffer_p[],
    int flags, int w, int precision, int size_)
{
    int x = BUFF_SIZE - 2;
    unsigned long int num = va_arg(p_f_list, unsigned long int);

    num = convert_size_unsgnd(num, size_);

    if (num == 0)
        buffer_p[x--] = '0';

    buffer_p[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer_p[x--] = (num % 10) + '0';
        num /= 10;
    }

    x++;

    return (write_unsgnd(0, x, buffer_p, flags, w, precision, size_));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * octal_p - Prints an unsigned number in octal notation
 * @p_f_list: List of arguments
 * @buffer_p: Buffer array to handle print
 * @flags: Calculates active flags
 * @w: Width specifier
 * @precision: Precision specification
 * @size_: Size specifier
 * Return: Number of characters printed
 */
int octal_p(va_list p_f_list, char buffer_p[],
    int flags, int w, int precision, int size_)
{

    int x = BUFF_SIZE - 2;
    unsigned long int num = va_arg(p_f_list, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(w);

    num = convert_size_unsgnd(num, size_);

    if (num == 0)
        buffer_p[x--] = '0';

    buffer_p[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer_p[x--] = (num % 8) + '0';
        num /= 8;
    }

    if (flags & F_HASH && init_num != 0)
        buffer_p[x--] = '0';

    x++;

    return (write_unsgnd(0, x, buffer_p, flags, w, precision, size_));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * hexadecimal_p - Prints an unsigned number in hexadecimal notation
 * @p_f_list: List of arguments
 * @buffer_p: Buffer array to handle print
 * @flags: Calculates active flags
 * @w: Width specifier
 * @precision: Precision specification
 * @size_: Size specifier
 * Return: Number of characters printed
 */
int hexadecimal_p(va_list p_f_list, char buffer_p[],
    int flags, int w, int precision, int size_)
{
    return (hexa_p(p_f_list, "0123456789abcdef", buffer_p,
        flags, 'x', w, precision, size_));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * hexa_upper_p - Prints an unsigned number in upper hexadecimal notation
 * @p_f_list: List of arguments
 * @buffer_p: Buffer array to handle print
 * @flags: Calculates active flags
 * @w: Width specifier
 * @precision: Precision specification
 * @size_: Size specifier
 * Return: Number of characters printed
 */
int hexa_upper_p(va_list p_f_list, char buffer_p[],
    int flags, int w, int precision, int size_)
{
    return (hexa_p(p_f_list, "0123456789ABCDEF", buffer_p,
        flags, 'X', w, precision, size_));
}

/************** PRINT HEXA NUMBER IN LOWER OR UPPER **************/
/**
 * hexa_p - Prints a hexadecimal number in lower or upper
 * @p_f_list: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer_p: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @w: Width specifier
 * @precision: Precision specification
 * @size_: Size specifier
 * Return: Number of characters printed
 */
int hexa_p(va_list p_f_list, char map_to[], char buffer_p[],
    int flags, char flag_ch, int w, int precision, int size_)
{
    int x = BUFF_SIZE - 2;
    unsigned long int num = va_arg(p_f_list, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(w);

    num = convert_size_unsgnd(num, size_);

    if (num == 0)
        buffer_p[x--] = '0';

    buffer_p[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer_p[x--] = map_to[num % 16];
        num /= 16;
    }

    if (flags & F_HASH && init_num != 0)
    {
        buffer_p[x--] = flag_ch;
        buffer_p[x--] = '0';
    }

    x++;

    return (write_unsgnd(0, x, buffer_p, flags, w, precision, size_));
}
