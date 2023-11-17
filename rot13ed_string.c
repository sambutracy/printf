#include "main.h"
/**
 * rot13_funct - prints a string using rot13
 * Return: lenght of the printed string 
 */
int rot13_funct(va_list char_arguments)
{
	int a;
	int b;
	char *string;
	char act[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(char_arguments, char*);
	if (string == NULL)
		return (-1);
	for (a = 0; string[a] != '\0'; a++)
	{
		for (b = 0; b <= 52; a++)
		{
			if (string[a] == act[b])
			{
				_putchar(rot[b]);
				break;
			}
		}
		if (b == 53)
			_putchar(string[a]);
	}
	return(string[a]);
}
