#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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
 * print_number - Prints an integer.
 * @n: The integer to print.
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
    _putchar(n % 10 + '0');
}

/**
 * print_unsigned - Prints an unsigned integer.
 * @n: The unsigned integer to print.
 */
void print_unsigned(unsigned int n)
{
    if (n / 10)
        print_unsigned(n / 10);
    _putchar(n % 10 + '0');
}

/**
 * print_octal - Prints an unsigned integer in octal.
 * @n: The unsigned integer to print.
 */
void print_octal(unsigned int n)
{
    if (n / 8)
        print_octal(n / 8);
    _putchar(n % 8 + '0');
}

/**
 * print_hex - Prints an unsigned integer in hexadecimal.
 * @n: The unsigned integer to print.
 * @uppercase: If non-zero, use uppercase letters.
 */
void print_hex(unsigned int n, int uppercase)
{
    char c;

    if (n / 16)
        print_hex(n / 16, uppercase);
    c = n % 16;
    if (c < 10)
        _putchar(c + '0');
    else
        _putchar(c + (uppercase ? 'A' - 10 : 'a' - 10));
}

/**
 * print_reverse - Prints a string in reverse.
 * @str: The string to reverse.
 */
void print_reverse(char *str)
{
    char *start = str;
    char *end;

    while (*str)
        str++;
    end = str - 1;
    while (end >= start)
    {
        _putchar(*end);
        end--;
    }
}

/**
 * print_pointer - Prints a pointer address.
 * @ptr: The pointer to print.
 */
void print_pointer(void *ptr)
{
    unsigned long addr = (unsigned long)ptr;
    _putchar('0');
    _putchar('x');
    print_hex(addr, 0);
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
    va_list args;
    unsigned int u;
    void *ptr;
    int len = 0;

    va_start(args, format);

    for (; *format; format++)
    {
        if (*format != '%')
        {
            _putchar(*format);
            len++;
            continue;
        }
        format++;
        switch (*format)
        {
        case 'd':
        case 'i':
            print_number(va_arg(args, int));
            len++;
            break;
        case 'u':
            u = va_arg(args, unsigned int);
            print_unsigned(u);
            len++;
            break;
        case 'o':
            u = va_arg(args, unsigned int);
            print_octal(u);
            len++;
            break;
        case 'x':
            u = va_arg(args, unsigned int);
            print_hex(u, 0);
            len++;
            break;
        case 'X':
            u = va_arg(args, unsigned int);
            print_hex(u, 1);
            len++;
            break;
        case 'r':
            print_reverse(va_arg(args, char *));
            len++;
            break;
        case 'c':
            _putchar(va_arg(args, int));
            len++;
            break;
        case 's':
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    _putchar(*str);
                    str++;
                    len++;
                }
            }
            break;
        case 'p':
            ptr = va_arg(args, void *);
            print_pointer(ptr);
            len += 2 + sizeof(void *) * 2; /* Length for '0x' and hexadecimal digits */
            break;
        case '%':
            _putchar('%');
            len++;
            break;
        default:
            _putchar('%');
            _putchar(*format);
            len += 2;
            break;
        }
    }

    va_end(args);
    return (len);
}
