#include "main.h"

/**
 * unsigned_funct - Prints an unsigned number in decimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed.
 */
int unsigned_funct(va_list types, char buffer[])
{
	int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(types, unsigned int);
	
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, 0, 0, 0, 0));
}

/**
 *octal_funct - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed.
 */
int octal_funct(va_list types, char buffer[])
{
	int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(types, unsigned int);
	
	if (num == 0)
		buffer[i--] = '0';
       	buffer[BUFF_SIZE - 1] = '\0';
	
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	i++;
	return (write_unsgnd(0, i, buffer, 0, 0, 0, 0));
}

/**
 * hexadecimal_funct - Prints an unsigned number in lowercase hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed.
 */
int hexadecimal_funct(va_list types, char buffer[])
{
	return print_hexa(types, "0123456789abcdef", buffer, 0, 'x', 0, 0, 0);
}

/**
 * hexa_upper_funct - Prints an unsigned number in uppercase hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed.
 */
int hexa_upper_funct(va_list types, char buffer[])
{
       	return print_hexa(types, "0123456789ABCDEF", buffer, 0, 'X', 0, 0, 0);
}

/**
 * hexa_lower_funct - Prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int hexa_lower_funct(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(types, unsigned int);
	
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags && num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * write_unsgnd - Writes an unsigned number to the standard output
 * @precision: Precision specification
 * @width: Get width
 * @flags:  Calculates active flags
 * @i: Buffer index
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed.
 */
int write_unsgnd(int precision, int width, char buffer[], int flags, int i)
{
	int printed_chars = 0;
	
	UNUSED(precision);
	UNUSED(width);
	UNUSED(flags);
	
	while (i < BUFF_SIZE - 1)
	{
		_putchar(buffer[i]);
		printed_chars++;
		i++;
	}
	return (printed_chars);
}
