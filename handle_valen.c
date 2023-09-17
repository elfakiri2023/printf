#include "main.h"
/**
*mic - function.
*@fmt: a character
*@list: valist
*@ind: pointer
*@buffer: array
*@flags: int 1
*@width: int 2
*@precision: int 3
*@size: int 4
*Return: not always 0
*/
int mic(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
int a, b = 0, c = -1;
fmt_j fmt_ius[] = {
	{'c', chrix}, {'s', gen}, {'%', dolf},
	{'i', ninsaz}, {'d', ninsaz}, {'b', buter},
	{'u', matab}, {'o', gran}, {'x', josh},
	{'X', sizeri}, {'p', sek}, {'S', audric},
	{'r', makab}, {'R', kiev}, {'\0', NULL}
};
for (a = 0; fmt_ius[a].fmt != '\0'; a++)
if (fmt[*ind] == fmt_ius[a].fmt)
return (fmt_ius[a].fn(list, buffer, flags, width, precision, size));

if (fmt_ius[a].fmt == '\0')
{
if (fmt[*ind] == '\0')
return (-1);
b += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')
b += write(1, " ", 1);
else if (width)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
b += write(1, &fmt[*ind], 1);
return (b);
}
return (c);
}
