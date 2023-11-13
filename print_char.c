#include "main.h"

/*
 * printfchar - it prints a character
 * @value: the input arguments
 * Return: 1 on success
 */
int printfchar(va_list value)
{
	char str;

	str = va_arg(value, int);
	_printchar(str);
	return (1);
}
