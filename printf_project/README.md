This function  produces output according to a format. It returns the number of characters printed (excluding the null byte used to end output to strings).
This function supports `%d` and `%i` conversion specifiers.
This function handles  the `%b` format specifier to print unsigned integers in binary format.
This function handles  the following conversion specifiers; u o x X.
This function formats and prints data to the standard output with minimal use of system calls by utilizing a local buffer.
This function includes support for the standard conversion specifiers as well as a custom specifier `%S`.
This function handles the `%p` conversion specifier for printing pointer addresses.
This function handles specific flag characters for non-custom conversion specifiers, including:- **`+`**: Forces a sign for numeric types. - **` ` (space)**: Inserts a space before positive numbers if no sign is given. - **`#`**: Used for alternate formatting.
This function  supports the following conversion specifiers and length modifiers:- `d` and `i` for signed integers, - `u` for unsigned integers, - `o` for octal numbers (not yet implemented), - `x` and `X` for hexadecimal numbers (not yet implemented), - `%` for percent sign.
This function produces output according to a specified format string.
This function handles various format specifiers, including precision for non-custom conversion specifiers.
This function handles the `0` flag for zero-padding of integers.
This function handles  different format specifiers, including handling the `-` flag character for non-custom conversion specifiers.
