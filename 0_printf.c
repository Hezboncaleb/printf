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
			{format++;
				switch (*format)
				{
					case ('b'):
						count += print_binary(va_arg(list, unsigned int));
						break;
					case ('c'):
						count += _putchar(va_arg(list, int));
						break;
					case ('d'):
					case ('i'):
						count += print_int((long int) va_arg(list, int));
						break;
					case ('u'):
						count += print_unsignedint((long int) va_arg(list, int));
						break;
					case ('s'):
						count += print_string((char *) va_arg(list, char *));
						break;
					case ('S'):
						count += print_String((char *) va_arg(list, char *));
						break;
					case ('X'):
					case ('o'):
					case ('p'):
					case ('x'):
						va_arg(list, void *);
						break;
					case ('%'):
						count += _putchar('%');
						break;
					default:
						format--, count += write(1, format, 1);
				}
			}
			format++;
		}
	}
	else
		return (0);
	va_end(list);
	return (count);
}

