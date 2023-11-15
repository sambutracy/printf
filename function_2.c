#include "main.h"

/**
 * p_int - Print int
 * @type: List a of arguments
 * Return: Number of chars printed
 */
int p_int(va_list type)
{
	int val = va_arg(type, int);

