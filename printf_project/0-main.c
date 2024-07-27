#include <stdio.h>
#include "main.h"

int main(void)
{
    int len;
    char *str = "Hello, world!";

    len = _printf("Character: %c\n", 'A');
    printf("Length: %d\n", len);

    len = _printf("String: %s\n", str);
    printf("Length: %d\n", len);

    len = _printf("Percent sign: %%\n");
    printf("Length: %d\n", len);

    return (0);
}
