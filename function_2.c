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
