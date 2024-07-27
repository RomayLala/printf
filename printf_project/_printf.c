#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 *
 * Return: On success 1, On error -1, and errno is set appropriately.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * _print_char - Prints a single character.
 * @c: The character to print.
 *
 * Return: The number of characters printed (1).
 */
int _print_char(char c)
{
_putchar(c);
return (1);
}

/**
 * _print_string - Prints a string.
 * @s: The string to print.
 *
 * Return: The number of characters printed.
 */
int _print_string(char *s)
{
int count = 0;

if (s == NULL)
s = "(null)";
while (*s)
{
_putchar(*s++);
count++;
}
return (count);
}

/**
 * _printf - Produces output according to a format.
 * @format: The format string containing zero or more directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
char *s;
char c;

va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
c = va_arg(args, int);
count += _print_char(c);
}
else if (*format == 's')
{
s = va_arg(args, char *);
count += _print_string(s);
}
else if (*format == '%')
{
_putchar('%');
count++;
}
else
{
_putchar('%');
_putchar(*format);
count += 2;
}
}
else
{
_putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
