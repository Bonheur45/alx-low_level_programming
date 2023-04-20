#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_c - prints a character
 * @list: list of arguments
 *@sep: separator to print before the argument
 */
void print_c(va_list list, char *sep)
{
	printf("%s%c", sep, va_arg(list, int));
}
/**
 * print_i - prints an integer
 *@list: list of arguments
 *@sep: separator to print before the argument
 */
void print_i(va_list list, char *sep)
{
	printf("%s%d", sep, va_arg(list, int));
}
/**
 * print_f - prints a float
 * @list: list of arguments
 * @sep: separator to print before the argument
 */
void print_f(va_list list, char *sep)
{
	printf("%s%f", sep, va_arg(list, double));
}
/**
 * print_s - prints a string
 * @list: list of arguments
 * @sep: separator to print before the argument
 */
void print_s(va_list list, char *sep)
{
	char *str = va_arg(list, char *);

	if (!str)
		str = "(nil)";
	printf("%s%s", sep, str);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *sep = "";
	va_list list;

	va_start(list, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				print_c(list, sep);
				break;
			case 'i':
				print_i(list, sep);
				break;
			case 'f':
				print_f(list, sep);
				break;
			case 's':
				print_s(list, sep);
				break;
			default:
				i++;
				continue;
		}
		sep = ", ";
		i++;
	}
	printf("\n");
	va_end(list);
}
