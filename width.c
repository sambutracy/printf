#include "main.h"

/**
 * get_width - to calculate the width
 * @format: Formatted string to print arguments.
 * @i: List of arguments
 * @lst: list of arguments.
 * Return: width.
 */

int get_width(const char *format, int *i, va_list lst)
{
	int flam_i;
	int w = 0;

	for (flam_i = *i + 1; format[flam_i] != '\0'; flam_i++)
	{
		if (is_digit(format[flam_i]))
		{
			w *= 10;
			w += format[flam_i] - '0';
		}
		else if (format[flam_i] == '*')
		{
			flam_i++;
			w = va_arg(lst, int);
			break;
		}
		else
			break;
	}
	*i = flam_i - 1;
	return (w);
}
