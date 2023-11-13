#include "main.h"
/**
 * string - prints string 
 *
 * @c: is a string format
 * Return: number of bytes used 
 */
int string(char *c)
{
	int cou = 0;

	if (c)
	{
		for (cou = 0; c[cou] != '\0'; cou++)
		{
			printchar(c[cou]);
		}
	}
	return (count);
}
