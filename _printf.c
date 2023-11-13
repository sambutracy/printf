#include "main.h"

void p_buffer(char b[], int *buff_ind);

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
	int val;
	int printed = 0;
	int printed_chars = 0;
	/*buff_ind - index to keep track of position in buffer*/
	int flag_, w, precision, s, buff_ind = 0;
	va_list lst;
	char b[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}
	va_start(lst, format);

	for (val = 0; format && format[val] != '\0'; val++)
	{
		if (format[val] != '%')
		{
			b[buff_ind++] = format[val];
			if (buff_ind == BUFF_SIZE)
			{
				p_buffer(b, &buff_ind);
			}

			/* putchar like: write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			p_buffer(b, &buff_ind);
			flag_ = get_flags(format, &val);
			w = get_width(format, &val, lst);
			precision = get_precision(format, &val, lst);
			s = get_size(format, &val);
			++val;
			printed = handle_print(format, &val, lst, b,
				flag_, w, precision, s);
			if (printed == -1)
			{
				return (-1);
			}
			printed_chars += printed;
		}
	}
	p_buffer(b, &buff_ind);

	va_end(lst);

	return (printed_chars);
}

/**
 * p_buffer - Prints the contents of the buffer if it exist
 * @b: Array
 * @buff_ind: index to keep track of position in buffer
 */

void p_buffer(char b[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &b[0], *buff_ind);
	}
	*buff_ind = 0;
}
