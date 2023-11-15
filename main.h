#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

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
 * struct frmt - structure op
 *
 * @frmt: The format
 * @fmt_t: the associated function
 */
typedef struct frmt {
	char *lett;
	int (*func)(va_list);
} check;


int _putchar(char c);
int _printf(const char *format, ...);
int p_int(va_list type);
int printfchar(va_list type);
int printstr(va_list type);
int printfpercentage(va_list type);

#endif

