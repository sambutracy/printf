#include "main.h"

/************** PRINT A STRING **************/

/**
 * printstr - to print a string character
 * @type: arguments of list 
 * Return: 1
 */
int printstr(va_list type)
{
	char *string;
	int i, len;

	string = va_arg(char_arg, char *);
	if (s == NULL)
	{
		string = "(null)";
		len = strlen(string);
		for (i = 0; i < len; i++)
			_putchar(string[i]);
		return (len);
	)
	else
	{
		len = _strlen(string);
		for (i = 0; i < len; i++)
			_putchar(s[i]);
		return (len);
	}
}

/*********** PRINT CHAR ***********/

/**
 * printfchar - it prints a char value
 * @type: arguments
 * Return: Number of chars printed
 */

int printfchar(va_list type)
{
	char c;

	c = va_arg(type, int);
	_putchar(c);
	return (1);
}


/**
 * printfpercent - it prints a percentage sign
 * @list: argument list
 * Return: Number of chars printed
 */

int printfpercent(__attribute__((unused))va_list type)
{
	_putchar('%');
	return (1);
}
