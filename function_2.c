#include "main.h"

/**
 * p_int - Print int
 * @type: List a of arguments
 * @b: Buffer array to handle print
 * @flag_: Calculates active flags
 * @w: get width.
 * @precision_: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int p_int(va_list type, char b[],
	int flag_, int w, int precision_, int s)
{
	int x = BUFF_SIZE - 2;
	int negative = 0;
	long int n = va_arg(type, long int);
	unsigned long int num;

	n = convert_size_number(n, s);

	if (n == 0)
		b[x--] = '0';

	b[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		negative = 1;
	}

	while (num > 0)
	{
		b[x--] = (num % 10) + '0';
		num /= 10;
	}

	x++;

	return (write_number(negative, x, b, flag_, w, precision_, s));
}
<<<<<<< HEAD

/**
 * p_pointer - to print the value of a pointer
 * @type: List a of arguments
 * @b: Buffer array
 * @flag_: to calculates active flags
 * @w: get width
 * @precision: to specify precision
 * @s: to specify size
 * Return: Number of chars printed.
 */

int p_pointer(va_list type, char b[],
	int flag_, int w, int precision, int s)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, len = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(type, void *);

	UNUSED(w);
	UNUSED(s);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	b[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		b[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flag_ & F_ZERO) && !(flag_ & F_MINUS))
		padd = '0';
	if (flag_ & F_PLUS)
		extra_c = '+', len++;
	else if (flag_ & F_SPACE)
		extra_c = ' ', len++;

	ind++;

	return (write_pointer(b, ind, len,
		w, flag_, padd, extra_c, padd_start));
=======
/**
 * print_pointer - Prints the value of a pointer variable
 * @type: List a of arguments
 * @buffer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @w: get width
 * @precision_: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed.
 */

int print_pointer(va_list type, char buffer[], int flag_, int w, int precision_, int s)
{
    char character_x = 0, p = ' ';
    int indbuff = BUFF_SIZE - 2, l = 2, p_padd = 1; /* l=2, for '0x' */
    unsigned long num;
    char mapto[] = "0123456789abcdef";
    void *address_p = va_arg(type, void *);

    UNUSED(w);
    UNUSED(s);

    if (address_p == NULL)
        return (write(1, "(nil)", 5));

    buffer[BUFF_SIZE - 1] = '\0';
    UNUSED(precision_);

    num = (unsigned long)address_p;

    while (num > 0)
    {
        buffer[indbuff--] = mapto[num % 16];
        num /= 16;
        l++;
    }

    if ((flag_ & F_ZERO) && !(flag_ & F_MINUS))
        p = '0';
    if (flag_ & F_PLUS)
        character_x = '+', l++;
    else if (flag_ & F_SPACE)
        character_x = ' ', l++;

    indbuff++;

    return (write_pointer(buffer, indbuff, l, w, flag_, p, character_x, p_padd));
}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @w: get width
 * @precision_: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int print_non_printable(va_list type, char buffer[], int flag_, int w, int precision_, int s)
{
    int i = 0, set = 0;
    char *string = va_arg(type, char *);

    UNUSED(flag_);
    UNUSED(w);
    UNUSED(precision_);
    UNUSED(s);

    if (string == NULL)
        return (write(1, "(null)", 6));

    while (string[i] != '\0')
    {
        if (is_printable(string[i]))
            buffer[i + set] = string[i];
        else
            set += append_hexa_code(string[i], buffer, i + set);

        i++;
    }

    buffer[i + set] = '\0';

    return (write(1, buffer, i + set));
}

/**
 * rot13string_func - Print a string in rot13.
 * @type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @w: get width
 * @precision_: Precision specification
 * @s: Size specifier
 * Return: Numbers of chars printed
 */

int rot13string_func(va_list type, char buffer[], int flag_, int w, int precision_, int s)
{
    char x;
    char *string;
    unsigned int i, j;
    int count = 0;
    char x[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char y[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    string = va_arg(type, char *);
    UNUSED(buffer);
    UNUSED(flag_);
    UNUSED(w);
    UNUSED(precision_);
    UNUSED(s);

    if (string == NULL)
        string = "(AHYY)";
    i = 0;
    while (string[i])
    {
        j = 0;
        while (x[j])
        {
            if (x[j] == string[i])
            {
                x = y[j];
                write(1, &x, 1);
                count++;
                break;
            }
            j++;
        }
        if (!x[j])
        {
            x = string[i];
            write(1, &x, 1);
            count++;
        }
        i++;
    }
    return (count);
}

/**
 * rev_print - Prints reverse string.
 * @type: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flag_:  Calculates active flags
 * @w: get width
 * @precision_: Precision specification
 * @s: Size specifier
 * Return: Numbers of chars printed
 */

int rev_print(va_list type, char buffer[], int flag_, int w, int precision_, int s)
{
    char *string;
    int i, count = 0;

    UNUSED(buffer);
    UNUSED(flag_);
    UNUSED(w);
    UNUSED(s);

    string = va_arg(type, char *);

    if (string == NULL)
    {
        UNUSED(precision_);
        string = ")Null(";
    }
    for (i = 0; string[i]; i++)
        ;

    for (i = i - 1; i >= 0; i--)
    {
        char z = string[i];
        write(1, &z, 1);
        count++;
    }
    return (count);
>>>>>>> 19a62d5cfea55bdbf7ac8bc2c13ba4c2341acf81
}
