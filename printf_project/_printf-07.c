#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variadic arguments
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    unsigned int i = 0;
    int count = 0;
    char *str;
    int num;
    char c;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            switch (format[i])
            {
            case 'd':
            case 'i':
                num = va_arg(args, int);
                count += _print_number(num);
                break;
            case 's':
                str = va_arg(args, char *);
                count += _print_string(str);
                break;
            case 'c':
                c = (char)va_arg(args, int);
                count += _putchar(c);
                break;
            case '+':
                /* Handle `+` flag - for signed numbers */
                break;
            case ' ':
                /* Handle ` ` flag - for signed numbers */
                break;
            case '#':
                /* Handle `#` flag - for octal and hexadecimal */
                break;
            default:
                count += _putchar('%');
                count += _putchar(format[i]);
                break;
            }
        }
        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return (count);
}

/**
 * _print_number - Print an integer
 * @n: Number to print
 * Return: Number of characters printed
 */
int _print_number(int n)
{
    int count = 0;

    if (n < 0)
    {
        count += _putchar('-');
        n = -n;
    }
    if (n / 10)
        count += _print_number(n / 10);
    count += _putchar(n % 10 + '0');
    return (count);
}

/**
 * _print_string - Print a string
 * @str: String to print
 * Return: Number of characters printed
 */
int _print_string(char *str)
{
    int count = 0;

    if (str == NULL)
        str = "(null)";
    while (*str)
        count += _putchar(*str++);
    return (count);
}

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 * Return: On success 1, On error -1
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

