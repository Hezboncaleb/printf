#include "main.h"
#include <stdio.h>
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
	int percent_num, i, classifier_index, len = _strlen(format);
	char *str = malloc(sizeof(char) * len);
	va_list list;

	if (format != NULL)
	{
		va_start(list, format), copy_values(format, str, len);
		classifier_index = 0, percent_num = num_percent(str);
		if (percent_num == 0)
		{
			count += write(1, format, len);
		}
		else
		{
			i = 0;
			while (i < percent_num)
			{
				classifier_index += index_percent(str, classifier_index) + 1;
				count += classifier_index;
				switch (str[classifier_index])
				{
					case ('c'):
						count += _putchar(va_arg(list, int)), classifier_index++;
						break;
					case ('d'):
					case ('i'):
						print_int((long int) va_arg(list, int)), classifier_index++;
						break;
					case ('u'):
						print_unsignedint((long int) va_arg(list, int)), classifier_index++;
						break;
					case ('f'):
						va_arg(list, double);
						break;
					case ('s'):
						count += print_string((char *) va_arg(list, char *)), classifier_index++;
						break;
					case ('X'):
					case ('o'):
					case ('p'):
					case ('x'):
						va_arg(list, void *);
						break;
					default:
						break;
				}
				i++;
			}
			count += write(1, &(str[classifier_index]), (len - classifier_index));

		}
	}
	else
		return (0);
	free(str), va_end(list);
	return (count);
}

