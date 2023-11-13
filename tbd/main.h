#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/*flags*/
#define F_MINUS 1
int printchar(char c);

/* functions for printing chars and strings */

int printstr(va_list type, char buff[],
		int flags, int width, int precision, int size);
int printfchar(va_list type, char buff[],
		int flag, int width, int precision, int size);
int printfpercent(va_list type, char buff[],
		int flag, int width, int precision, int size);
/*width handle*/
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);

int _printf(const char *format, ...);
#endif
