#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define F_MINUS 1
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

int printchar(char c);

int _printf(const char *format, ...);
/* functions for printing chars and strings */

int printstr(va_list type, char buff[],
                int flags, int width, int precision, int size);
int printfchar(va_list type, char buff[],
                int flag, int width, int precision, int size);
int printfpercent(va_list type, char buff[],
                int flag, int width, int precision, int size);

int _printf(const char *format, ...);
/*function for printing integer(d% i%)*/

int p_int(va_list typeof, char b[],
        int flag_int, int w, int precision_, int s)

/*string and printf */
int string(char *c);
#endif
