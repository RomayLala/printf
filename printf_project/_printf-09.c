#include "main.h"
#include <stdlib.h>

/**
 * _print_number - Prints a number with optional width
 * @num: The number to print
 * @width: The field width
 */
void _print_number(int num, int width)
{
    int count = 0, temp = num, divisor = 1;

    if (num < 0)
    {
        _putchar('-');
        num = -num;
        width--;
    }

    while (temp / 10)
    {
        count++;
        temp /= 10;
        divisor *= 10;
    }

    while (width > count + 1)
    {
        _putchar(' ');
        width--;
    }

    while (divisor > 0)
    {
        _putchar((num / divisor) % 10 + '0');
        divisor /= 10;
    }
}

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0, width;
    char *str;

    va_start(args, format);
    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            width = 0;

            while (format[i] >= '0' && format[i] <= '9')
            {
                width = width * 10 + (format[i] - '0');
                i++;
            }

            switch (format[i])
            {
                case 'c':
                    _putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (!str)
                        str = "(null)";
                    while (*str)
                    {
                        _putchar(*str++);
                        count++;
                    }
                    break;
                case 'd':
                case 'i':
                    _print_number(va_arg(args, int), width);
                    count++;
                    break;
                case '%':
                    _putchar('%');
                    count++;
                    break;
                default:
                    _putchar('%');
                    _putchar(format[i]);
                    count += 2;
                    break;
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }
    va_end(args);
    return (count);
}
