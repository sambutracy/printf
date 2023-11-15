#include "main.h"

/**
 * get_precision - for calculating precision
 * @format: Formatted string to print arguments to
 * @i: Arguments to print.
 * @lst: list of arguments
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list lst)
{
	int flam_i = *i + 1;
	int pre = -1;

	if (format[flam_i] != '.')
		return (pre);

	pre = 0;

	for (flam_i += 1; format[flam_i] != '\0'; flam_i++)
	{
		if (is_digit(format[flam_i]))
		{
			pre *= 10;
			pre += format[flam_i] - '0';
		}
		else if (format[flam_i] == '*')
		{
			flam_i++;
			pre = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*i = flam_i - 1;

	return (pre);
}
