#include "main.h"
#include <stdarg.h>
/**
 * rev_function - prints a string in reverse 
 * Return : length of the printed string 
 */
int rev_function(va_list char_arguments)
{
	int i = 0;
	int j;
	char *p = va_arg(char_arguments, char *);

	if(!p)
		p = "(null)";
	while (p[i])
		i++;
	for (j = i - 1; j >= 0; j--)
		_putchar(p[j]);
	return (i);
}
