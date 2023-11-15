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

	if (val < 0)
	{
		_putchar('-');
		x++;
		val = -val;
	}
	else
	{
		while (val != 0)
		{
			dig = val % 10;
			_putchar(dig + '0');
			x++;
			val /= 10;
		}
	}
	return x;
}
			

