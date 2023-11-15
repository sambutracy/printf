#include "main.h"

/**
 * _putchar - Prints a character to the standard output
 * @c: The character to be printed
 *
 * Return: 1 (the number of characters printed)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
