#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _putchar(char c); /* Prototype for _putchar */
int _printf(const char *format, ...);
void print_number(int num, char padding, int width);
int _puts(char *str);
int _print_string(char *str);
void _print_number(int num, int width);

#endif /* MAIN_H */
