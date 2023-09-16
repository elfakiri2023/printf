#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define S_LONG 2
#define S_SHORT 1

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct fmt - struct op.
 * @fmt: format
 * @fn: associated function.
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - struct op.
 * @fmt: format
 * @fm_t: associated function.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
void buffer_print(char buffer[], int *buff_ind);
int print_handler(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
int print_a_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_a_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_a_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_a_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_a_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_a_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_a_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_a_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_a_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_a_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_a_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int the_flags(const char *format, int *i);
int the_width(const char *format, int *i, va_list list);
int the_precision(const char *format, int *i, va_list list);
int the_size(const char *format, int *i);
int reverse_print(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_a_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int handle_char_write(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_a_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_a_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);
long int convert_number_size(long int num, int size);
long int convert_unsgnd_size(unsigned long int num, int size);
int check_if_printable(char);
int append_the_hexa_code(char, char[], int);
int check_if_digit(char);
#endif


