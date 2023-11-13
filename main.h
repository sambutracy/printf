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
/*string and printf */
int string(char *c);
#endif
