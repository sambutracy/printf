#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
int printchar(char c);
int printfchar(va_list value);

/* functions for printing chars and strings */

int printstr(va_list type, char buff[],
		int flags, int width, int precision, int size);
int printfchar(va_list type, char buff[],
		int flag, int width, int precision, int size);
int printfpercent(va_list type, char buff[],
		int flag, int width, int precision, int size);

int _printf(const char *format, ...);
#endif
