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
#define F_PLUS 2
#define F_ZER0 4
#define F_HASH 8
#define F_SPACE 16

/* size */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct frmt - structure op
 *
 * @frmt: The format
 * @f: the associated function
 */

struct frmt
{
	char frmt;
	int (*f)(va_list, char[], int, int, int, int);
};

typedef struct frmt frmt_t;
int printchar(char c);
int _printf(const char *format, ...);
int handle_print(const char *frmt, int *i,
va_list lst, char b[], int flag_, int w, int precision, int s);

/* functions for printing chars %c, percentage &%%  and strings %s */

int printstr(va_list type, char b[],
		int flag_, int w, int precision, int s);
int printfchar(va_list type, char b[],
		int flag_, int w, int precision, int s);
int printfpercent(va_list type, char b[],
		int flag_, int w, int precision, int s);

/*function for printing integer(d% i%)*/

int p_int(va_list type, char b[],
		int flag_, int w, int precision_, int s);
int p_binary(va_list type, char b[],
		int flag_, int w, int precision, int s);
int p_unsigned(va_list type, char b[],
		int flag_, int w, int precision, int s);
int p_hexadec(va_list type, char b[],
		int flag_, int w, int precision, int s);
int p_hex_upper(va_list type, char b[],
		int flag_, int w, int precision, int s);
int p_hexa(va_list type, char map_to[],
		char b[], int flag_, char flag_ch, int w, int precision, int s);

/* funtions for non printable */
int p_non_printable(va_list type, char b[],
		int flag_, int w, int precision, int s);

/* functions to handle other specifiers */

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list lst);
int get_precision(const char *format, int *i, va_list lst);
int get_size(const char *format, int *i);

/* string in reverse */
int p_reverse(va_list type, char b[],
		int flag_, int w, int precision, int s);

/* print string in rot 13 */
int p_rot13string(va_list type, char b[],
		int flag_, int w, int precision, int s);

/* handle width (w) */
int handle_write_char(char c, char b[],
		int flag_, int w, int precision, int s);
int write_number(int is_positive, int ind, char b[],
		int flag_, int w, int precision, int s);
int write_num(int ind, char bff[], int flag_, int w, int precision,
		int len, char padd, char extra_c);
int write_pointer(char b[], int ind, int len,
		int w, int flag_, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char b[],
	int flag_, int w, int precision, int s);

/*string and printf */
int string(char *c);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int s);
long int convert_size_unsgnd(unsigned long int num, int s);
#endif
