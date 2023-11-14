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
}
