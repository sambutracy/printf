#include "main.h"
/**
 */
int _printf(const char *format, ...)
{
	unsigned int x;
	unsigned int f = 0;
	unsigned int countstring;

	va_list arguments;

	if (!format || (format[0] == '&' && format[1] == '\0'))
		return (-1);

	va_start(arguments, format);
	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			printchar(format[x]);
		}
		else if(format[x] == '%' && format[x + 1] == 'c')
		{
			printchar (va_arg(arguments, int));
			x++;
		}
		else if (format[x + 1] == 's')
		{
			countstring = string(va_arg(arguments, char*));
			x++;
			f += (countstring - 1);
		}
		else if (format[x + 1] == '%')
		{
			printchar ('%');
		}
		x++;
	
	}

	va_end(arguments);
	return (f);
}
