#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct.
 *
 * @unsign: flag if value is unsigned
 *
 * @plus_flag: on if plus_flag specified.
 * @space_flag: on if hashtag_flag specified.
 * @hashtag_flag: on if _flag specified.
 * @zero_flag: on if _flag specified.
 * @minus_flag: on if _flag specified.
 *
 * @width: field width specified.
 * @precision: field precision specified.
 *
 * @h_modifier: on if h_modifier is specified.
 * @l_modifier: on if l_modifier is specified.
 *
 */

typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c */
int print_a_char(va_list ap, params_t *params);
int print_a_int(va_list ap, params_t *params);
int print_a_string(va_list ap, params_t *params);
int print_a_percent(va_list ap, params_t *params);
int print_an_S(va_list ap, params_t *params);

/* number.c */
char *convert(long int num, int base, int flags, params_t *params);
int print_a_unsigned(va_list ap, params_t *params);
int print_a_address(va_list ap, params_t *params);

/* specifier.c */
int (*get_the_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_the_flag(char *s, params_t *params);
int get_the_modifier(char *s, params_t *params);
char *get_the_width(char *s, params_t *params, va_list ap);

/* convert_number.c */
int print_a_hex(va_list ap, params_t *params);
int print_a_HEX(va_list ap, params_t *params);
int print_a_binary(va_list ap, params_t *params);
int print_an_octal(va_list ap, params_t *params);

/* simple_printers.c */
int print_from_to(char *start, char *stop, char *except);
int print_a_rev(va_list ap, params_t *params);
int print_a_rot13(va_list ap, params_t *params);

/* print_a_number.c */
int check_isdigit(int c);
int get_strlen(char *s);
int print_a_number(char *str, params_t *params);
int print_a_number_right_shift(char *str, params_t *params);
int print_a_number_left_shift(char *str, params_t *params);

/* params.c */
void init_params(params_t *params, va_list ap);

/* string_fields.c */
char *get_precision(char *p, params_t *params, va_list ap);

/* _prinf.c */
int _printf(const char *format, ...);

#endif
