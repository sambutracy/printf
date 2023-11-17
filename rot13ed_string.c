#include "main.h"
/**
 * rot13_funct - prints a string using rot13
 * Return: lenght of the printed string 
 */
int rot13_funct(va_list char_arguments)
{
	int a;
	char *string;
	int index ;
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(char_arguments, char*);

	if (string == NULL)
		return (-1);
	for (a = 0; string[a] != '\0'; a++)
	{
		if(string[a] >= 'A' && string[a] <= 'Z')
		{
			index = string[a] - 'A';
			_putchar(rot[index]);
		}
		else if(string[a] >= 'a' && string[a] <= 'z')
		{
			index =string[a] - 'a' + 26;
			_putchar(rot[index]);
		}
		else
		{
			_putchar(string[a]);
		}
	}
	return (a);
}
