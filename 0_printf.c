#include "main.h"

/**
 * _printf - write output to stdout, the standard output stream
 * @format: is a character string. The format string is composed
 * of zero or more directives.
 * Return: number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	size_t count = 0;
	va_list list;

	if (format != NULL)
	{
		va_start(list, format);

		while (*format)
		{
			if (*format != '%')
				count += write(1, format, 1);
			else if (*format == '%' && *(format - 1) == 92)
				count += _putchar('%');
			else
			{
				format++;
				count += handle_specifiers(format, list);
			}
			format++;
		}
	}
	else
		return (0);
	va_end(list);
	return (count);
}

