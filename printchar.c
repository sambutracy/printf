#include "main.h"
/**
 * printchar - print a char
 * @c: char input
 * Return: 1
 */
int printchar(char c)
{
	return (write(1, &c, 1));
}
