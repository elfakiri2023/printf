#include "main.h"

/**
 * get_the_specifier - finds the format function.
 * @s: string of the format.
 * Return: the number of bytes printed.
 */

int (*get_the_specifier(char *s))(va_list ap, params_t *params)

{
	specifier_t specifiers[] = {
		{"c", print_a_char},
		{"d", print_a_int},
		{"i", print_a_int},
		{"s", print_a_string},
		{"%", print_a_percent},
		{"b", print_a_binary},
		{"o", print_an_octal},
		{"u", print_a_unsigned},
		{"x", print_a_hex},
		{"X", print_a_HEX},
		{"p", print_a_address},
		{"S", print_an_S},
		{"r", print_a_rev},
		{"R", print_a_rot13},
		{NULL, NULL}
	};

	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format function.
 * @s: string of the format.
 * @ap: argument pointer.
 * @params: the parameters struct.
 * Return: the number of bytes printed.
 */

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_the_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_the_flag - finds the flag functions.
 * @s: the format string.
 * @params: the parameters struct.
 * Return: if flag was valid.
 */

int get_the_flag(char *s, params_t *params)

{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_the_modifier - finds the modifier function.
 * @s: string for format.
 * @params: parameter structure.
 * Return: if modifier was valid.
 */

int get_the_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_the_width - gets the width from the format string.
 * @s: the format string.
 * @params: the parameters struct.
 * @ap: the argument pointer.
 * Return: new pointer.
 */

char *get_the_width(char *s, params_t *params, va_list ap)

	/* TODO */
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (check_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
