#include "main.h"

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to write.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_number - Prints a number with padding.
 * @num: The number to print.
 * @padding: The padding character.
 * @width: The minimum width of the printed number.
 */
void print_number(int num, char padding, int width)
{
    char buffer[12];
    int i = 11;
    int is_negative = num < 0 ? 1 : 0;
    int len = 0;

    buffer[i--] = '\0';
    if (is_negative)
        num = -num;

    do {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
        len++;
    } while (num > 0);

    if (is_negative) {
        buffer[i--] = '-';
        len++;
    }

    while (len < width) {
        buffer[i--] = padding;
        len++;
    }

    while (buffer[++i])
        _putchar(buffer[i]);
}

/**
 * print_unsigned - Prints an unsigned number.
 * @num: The number to print.
 * @base: The base to print in.
 */
void print_unsigned(unsigned int num, int base)
{
    char *digits = "0123456789abcdef";
    char buffer[33];
    int i = 32;

    buffer[i--] = '\0';

    do {
        buffer[i--] = digits[num % base];
        num /= base;
    } while (num > 0);

    while (buffer[++i])
        _putchar(buffer[i]);
}

/**
 * _printf - Prints formatted output to stdout.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, len = 0;
    char padding;
    int width;
    char *str;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format && format[i]) {
        if (format[i] == '%') {
            i++;
            padding = (format[i] == '0') ? '0' : ' ';
            width = 0;
            if (format[i] >= '0' && format[i] <= '9') {
                while (format[i] >= '0' && format[i] <= '9')
                    width = width * 10 + (format[i++] - '0');
            }
            switch (format[i]) {
                case 'd':
                case 'i':
                    print_number(va_arg(args, int), padding, width);
                    break;
                case 'u':
                    print_unsigned(va_arg(args, unsigned int), 10);
                    break;
                case 'o':
                    print_unsigned(va_arg(args, unsigned int), 8);
                    break;
                case 'x':
                    print_unsigned(va_arg(args, unsigned int), 16);
                    break;
                case 'X':
                    {
                        unsigned int num = va_arg(args, unsigned int);
                        char buffer[33];
                        int j = 32;
                        buffer[j--] = '\0';
                        do {
                            buffer[j--] = "0123456789ABCDEF"[num % 16];
                            num /= 16;
                        } while (num > 0);
                        while (buffer[++j])
                            _putchar(buffer[j]);
                    }
                    break;
                case 'c':
                    _putchar(va_arg(args, int));
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (!str)
                        str = "(null)";
                    while (*str)
                        _putchar(*str++);
                    break;
                case 'p':
                    {
                        unsigned long addr = (unsigned long)va_arg(args, void *);
                        int shift;
                        _putchar('0');
                        _putchar('x');
                        for (shift = (sizeof(addr) * 8) - 4; shift >= 0; shift -= 4)
                            _putchar("0123456789abcdef"[(addr >> shift) & 0xF]);
                    }
                    break;
                case '%':
                    _putchar('%');
                    break;
                default:
                    _putchar('%');
                    _putchar(format[i]);
            }
            i++;
        } else {
            _putchar(format[i++]);
        }
        len++;
    }

    va_end(args);

    return (len);
}
