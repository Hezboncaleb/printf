#include "main.h"

/**
 * handle_specifiers - handles format specifiers
 * @format: the pointer to the format specifier
 * @list: list
 * Return: count
 */

size_t handle_specifiers(const char *format, va_list list)
{
	size_t count = 0;

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
	return (count);
}
