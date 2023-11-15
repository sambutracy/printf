#include "main.h"

/**
 * p_int - Print int
 * @type: List a of arguments
 * Return: Number of chars printed
 */
int p_int(va_list type)
{
	int val = va_arg(type, int);
	int x = 0;
	int dig;
	unsigned int n;

	dig = 1;

	if (val < 0)
	{
		x += _putchar('-');
		n = val * -1;
	}
	else
	{
		n = val;
	}
	for (; n / dig > 9;)
		dig *= 10;

	for (; dig != 0;)
	{
		x += _putchar('0' + n / dig);
		n %= dig;
		dig /= 10;
	}

	return (x);
}
