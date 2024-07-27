#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to print.
 *
 * Return: On success, 1. On error, -1.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * print_number - Prints an integer in decimal format.
 * @n: The number to print.
 */
void print_number(int n)
{
if (n < 0)
{
_putchar('-');
n = -n;
}
if (n / 10)
print_number(n / 10);
_putchar((n % 10) + '0');
}

/**
 * print_unsigned - Prints an unsigned integer in decimal format.
 * @n: The number to print.
 */
void print_unsigned(unsigned int n)
{
if (n / 10)
print_unsigned(n / 10);
_putchar((n % 10) + '0');
}

/**
 * print_octal - Prints an unsigned integer in octal format.
 * @n: The number to print.
 */
void print_octal(unsigned int n)
{
if (n / 8)
print_octal(n / 8);
_putchar((n % 8) + '0');
}

/**
 * print_hex - Prints an unsigned integer in hexadecimal format.
 * @n: The number to print.
 * @uppercase: If 1, print in uppercase, otherwise lowercase.
 */
void print_hex(unsigned int n, int uppercase)
{
const char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
if (n / 16)
print_hex(n / 16, uppercase);
_putchar(digits[n % 16]);
}

/**
 * _printf - Custom printf function.
 * @format: The format string.
 * @...: The values to format and print.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
unsigned int i = 0, count = 0;
va_list args;

va_start(args, format);
while (format && format[i])
{
if (format[i] == '%' && (format[i + 1] == 'u' || format[i + 1] == 'o' ||
format[i + 1] == 'x' || format[i + 1] == 'X' || format[i + 1] == 'd'))
{
if (format[i + 1] == 'd')
{
int num = va_arg(args, int);
print_number(num);
}
else
{
unsigned int num = va_arg(args, unsigned int);
if (format[i + 1] == 'u')
print_unsigned(num);
else if (format[i + 1] == 'o')
print_octal(num);
else if (format[i + 1] == 'x')
print_hex(num, 0);
else if (format[i + 1] == 'X')
print_hex(num, 1);
}
count += 1; /* For the '%' character */
count += 1; /* For the format specifier */
i += 2; /* Skip the format specifier */
}
else
{
_putchar(format[i]);
count++;
i++;
}
}
va_end(args);
return (count);
}
