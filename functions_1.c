#include "main.h"

/************** PRINT A STRING **************/

/**
 * printstr - to print a string character
 * @type: arguments of list a
 * @b: Buffer array handling print
 * @flag_: active flags
 * @w: calculates width
 * @precision: specify the precision
 * @s: specify size
 * Return: the number of char printed
 */
int printstr(va_list type, char b[],
	int flag_, int w, int precision, int s)
{
	int len = 0, i;
	char *string = va_arg(type, char *);

	UNUSED(b);
	UNUSED(flag_);
	UNUSED(w);
	UNUSED(precision);
	UNUSED(s);

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

	if (w > len)
	{
		if (flag_ & F_MINUS)
		{
			write(1, &string[0], len);
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &string[0], len);
			return (w);
		}
	}

	return (write(1, string, len));
}

/*********** PRINT CHAR ***********/

/**
 * printfchar - it prints a char value
 * @type: arguments
 * @b: Buffer array
 * @flag_: Calculate active flags
 * @w: Width
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int printfchar(va_list type, char b[],
	int flag_, int w, int precision, int s)
{
	char c = va_arg(type, int);

	return (handle_write_char(c, b, flag_, w, precision, s));
}

/*********** PRINT PERCENT SIGN ***********/

/**
 * printfpercent - it prints a percentage sign
 * @type: arguments
 * @b: Buffer array
 * @flag_: to calculate active flags
 * @w: get width.
 * @precision: specify precision
 * @s: specify size
 * Return: Number of chars printed
 */

int printfpercent(va_list type, char b[],
	int flag_, int w, int precision, int s)
{
	UNUSED(type);
	UNUSED(b);
	UNUSED(flag_);
	UNUSED(w);
	UNUSED(precision);
	UNUSED(s);
	return (write(1, "%%", 1));
}
