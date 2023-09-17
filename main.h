#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16


#define S_LONG 2
#define S_SHORT 1

/**
*struct fmt - function.
*@fmt: character
*@fn: pointer
*/
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};

/**
*typedef struct fmt fmt_j - function.
*@fmt: variable
*@fm_t: 2nd variable
*/
typedef struct fmt fmt_j;

int _printf(const char *format, ...);
int mic(const char *fmt, int *ind,
va_list list, char buffer[], int flags, int width, int precision, int size);


int chrix(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int gen(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int dolf(va_list types, char buffer[],
	int flags, int width, int precision, int size);


int ninsaz(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int buter(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int matab(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int gran(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int josh(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int sizeri(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int ced(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);


int audric(va_list types, char buffer[],
	int flags, int width, int precision, int size);


int sek(va_list types, char buffer[],
	int flags, int width, int precision, int size);


int fakiri(const char *format, int *i);
int badr(const char *format, int *i, va_list list);
int just(const char *format, int *i, va_list list);
int jul(const char *format, int *i);


int makab(va_list types, char buffer[],
	int flags, int width, int precision, int size);


int kiev(va_list types, char buffer[],
	int flags, int width, int precision, int size);


int ravoinn(char c, char buffer[],
	int flags, int width, int precision, int size);
int can(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int kany(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int kaba(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int cal(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);


int mar(char);
int helloo(char, char[], int);
int mat(char);

long int winn(long int num, int size);
long int bazim(unsigned long int num, int size);

#endif
