#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/* flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* size */
#define S_LONG 2
#define S_SHORT 1
/**
 * struct frmt - Structure for format checking
 * @lett: The input variable (provide a brief description)
 * @func: The associated function for the format
 */

typedef struct frmt
{
	char *lett;
	int (*func)(va_list);
} check;

int _putchar(char c);
int _printf(const char *format, ...);
int p_int(va_list type);
int printfchar(va_list type);
int printstr(va_list type);
int printfpercentage(va_list type);
int rev_function(va_list char_arguments);
int rot13_funct(va_list char_arguments);

/**/
int unsigned_funct(va_list types, char buffer[]);
int octal_funct(va_list types, char buffer[]);
int hexadecimal_funct(va_list types, char buffer[]);
int hexa_upper_funct(va_list types, char buffer[]);
int hexa_lower_funct(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);
int write_unsgnd(int precision, int width, char buffer[], int flags, int i, int size);

#endif

