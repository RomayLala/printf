#include "main.h"

/**
 * _printf - Custom printf function that supports %p for pointer addresses.
 * @format: The format string containing the text and format specifiers.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *ptr;
	void *address;
	unsigned long addr;
	char hex_chars[] = "0123456789abcdef";
	int count = 0;

	va_start(args, format);

	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr != '%')
		{
			write(1, ptr, 1);
			count++;
			continue;
		}

		ptr++;
		if (*ptr == 'p')
		{
			address = va_arg(args, void *);
			addr = (unsigned long)address;

			write(1, "0x", 2);
			count += 2;

			if (addr == 0)
			{
				write(1, "0", 1);
				count++;
			}
			else
			{
				char buffer[16];
				int i = 0;

				while (addr > 0)
				{
					buffer[i++] = hex_chars[addr % 16];
					addr /= 16;
				}

				for (--i; i >= 0; i--)
					write(1, &buffer[i], 1);

				count += i + 1;
			}
		}
	}

	va_end(args);
	return (count);
}
