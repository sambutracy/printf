#include "main.h"

/************** PRINT A STRING **************/

/**
 * printstr - to print a string character
 * @types: arguments of list a
 * @buff: Buffer array handling print
 * @flag: active flags
 * @width: calculates width
 * @precision: specify the precision
 * @size: specify size
 * Return: the number of char printed
 */
int printstr(va_list type, char buff[],
	int flag, int width, int precision, int size)
{
	int len = 0, i;
	char *string = va_arg(type, char *);

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
	{
		string = "(null)";
		if (precision >= 6)
			string = "      ";
	}
	while (string[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flag & F_MINUS)
		{
			write(1, &string[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &string[0], len);
			return (width);
		}
	}

	return (write(1, string, len));
}

/*********** PRINT CHAR ***********/

/**
 * printfchar - it prints a char value
 * @type: arguments
 * @buff: Buffer array
 * @flag: Calculate active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int printfchar(va_list type, char buff[],
	int flag, int width, int precision, int size)
{
	char c = va_arg(type, int);

	return (handle_write_char(c, buff, flag, width, precision, size));
}

/*********** PRINT PERCENT SIGN ***********/

/**
 * printfpercent - it prints a percentage sign
 * @type: arguments
 * @buff: Buffer array
 * @flag: to calculate active flags
 * @width: get width.
 * @precision: specify precision
 * @size: specify size
 * Return: Number of chars printed
 */

int printfpercent(va_list type, char buff[],
	int flag, int width, int precision, int size)
{
	UNUSED(type);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
