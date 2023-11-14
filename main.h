#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* printf functions */
void buffer_p(char buffer[], int *buff_i);
int _printf(const char *format, ...);

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
	char frmt;
	int (*fmt_t)(va_list, char[], int, int, int, int);
} frmt_t;

int printchar(char c);
int _printf(const char *format, ...);
int handle_print(const char *frmt, int *i, va_list lst, char b[], int flag_, int w, int precision_, int s);

/* functions for printing chars %c, percentage &%%, and strings %s */
int printstr(va_list type, char b[], int flag_, int w, int precision_, int s);
int printfchar(va_list type, char b[], int flag_, int w, int precision_, int s);
int printfpercent(va_list type, char b[], int flag_, int w, int precision_, int s);

/* function for printing integer(d% i%) */
int p_int(va_list type, char b[], int flag_, int w, int precision_, int s);
int p_binary(va_list type, char b[], int flag_, int w, int precision_, int s);
int p_unsigned(va_list type, char b[], int flag_, int w, int precision_, int s);
int p_hexadec(va_list type, char b[], int flag_, int w, int precision_, int s);
int p_hex_upper(va_list type, char b[], int flag_, int w, int precision_, int s);
int p_hexa(va_list type, char map_to[], char b[], int flag_, char flag_ch, int w, int precision_, int s);

/* functions for non-printable */
int p_non_printable(va_list type, char b[], int flag_, int w, int precision_, int s);

/* functions to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list lst);
int get_precision(const char *format, int *i, va_list lst);
int get_size(const char *format, int *i);

/* functions to print pointer, non-printable, reverse string in rot13 */
int print_pointer(va_list type, char buffer[], int flag_, int w, int precision_, int s);
int print_non_printable(va_list type, char buffer[], int flag_, int w, int precision_, int s);
int rot13string_func(va_list type, char buffer[], int flag_, int w, int precision_, int s);
int rev_print(va_list type, char buffer[], int flag_, int w, int precision_, int s);

/* handle width (w) */
int handle_write_char(char c, char b[], int flag_, int w, int precision_, int s);
int write_number(int is_positive, int ind, char b[], int flag_, int w, int precision_, int s);
int write_num(int ind, char bff[], int flag_, int w, int precision_, int len, char padd, char extra_c);
int write_pointer(char b[], int ind, int len, int w, int flag_, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char b[], int flag_, int w, int precision, int s);

/* string and printf */
int string(char *c);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int s);
long int convert_size_unsgnd(unsigned long int num, int s);

/* functions for hexadecimals octal unsigned decimal */
int hexa_p(va_list list, char map_to[], char b[], int flag_, char flag_ch, int w, int precision_, int s);
int hexa_upper_p(va_list list, char b[], int flag_, int w, int precision_, int s);
int hexadec(va_list list, char b[], int flag_, int w, int precision_, int s);
int p_octal(va_list list, char b[], int flag_, int w, int precision_, int s);
int p_unsigned(va_list list, char b[], int flag_, int w, int precision_, int s);
/*handleprint*/
int p_octal(va_list type, char b[], int flag_, int w, int precision_, int s);
int p_pointer(va_list type, char b[], int flag_, int w, int precision_, int s);
int p_reverse(va_list type, char b[], int flag_, int w, int precision_, int s);
int p_rot13string(va_list type, char b[], int flag_, int w, int precision_, int s);

#endif

