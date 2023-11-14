#include "main.h"

/**
 * get_size - to calculate the size to cas for argument
 * @format: Formatted string to print arguments
 * @i: List of arguments
 * Return: Size
 */

int get_size(const char *format, int *i)
{
	int flam_i = *i + 1;
	int s = 0;

	if (format[flam_i] == 'l')
		s = S_LONG;
	else if (format[flam_i] == 'h')
		s = S_SHORT;
	if (s == 0)
		*i = flam_i - 1;
	else
		*i = flam_i;
	return (s);
}
