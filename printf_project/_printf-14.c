#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h> /* For strlen */

/* _putchar - Writes a character to stdout.
 * @c: The character to write.
 *
 * Return: On success 1, On error -1.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/* handle_rot13 - Encodes a string using ROT13 and prints it.
 * @str: The string to encode and print.
 */
void handle_rot13(char *str)
{
    char c;

    while (*str)
    {
        c = *str;
        if (c >= 'a' && c <= 'z')
            c = ((c - 'a' + 13) % 26) + 'a';
        else if (c >= 'A' && c <= 'Z')
            c = ((c - 'A' + 13) % 26) + 'A';
        _putchar(c);
        str++;
    }
}

/* _printf - Custom printf function to handle various specifiers.
 * @format: The format string containing the text to be printed.
 * @...: Additional arguments for format specifiers.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    unsigned int i = 0, count = 0;
    char *str;
    char *original_str;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'R')
            {
                _putchar('D'); /* Debug: Indicate handling of %R */
                _putchar('R');
                _putchar(':');
                
                original_str = va_arg(args, char *);
                str = original_str;
                
                if (str)
                {
                    /* Print the original string */
                    _putchar(' ');
                    _putchar('O');
                    _putchar('r');
                    _putchar('i');
                    _putchar('g');
                    _putchar('i');
                    _putchar('n');
                    _putchar('a');
                    _putchar('l');
                    _putchar(':');
                    _putchar(' ');
                    while (*str)
                    {
                        _putchar(*str++);
                        count++;
                    }
                    
                    /* Print a new line for clarity */
                    _putchar('\n');
                    
                    /* Handle ROT13 encoding */
                    _putchar('R');
                    _putchar('o');
                    _putchar('t');
                    _putchar('1');
                    _putchar('3');
                    _putchar(':');
                    _putchar(' ');
                    handle_rot13(original_str);
                    count += strlen(original_str); /* Update count for printed string */
                }
                else
                {
                    /* Print (nil) and update count */
                    _putchar('(');
                    _putchar('n');
                    _putchar('i');
                    _putchar('l');
                    _putchar(')');
                    count += 5; /* For "(nil)" */
                }
            }
            else
            {
                /* Print '%' followed by the specifier */
                _putchar('%');
                _putchar(format[i]);
                count += 2;
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
    return count;
}
