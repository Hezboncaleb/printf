#include "main.h"

/**
 * index_percent - finds the index of percent sign
 * @str: string
 * @start_index: index to start finding the sign
 * Return: index of percent sign
 */

int index_percent(char *str, int start_index)
{
	int count = 0, i = start_index;

	while (str[i] != '\0')
	{
		if ((str[i] == '%' && str[i + 1] != '%')
				|| (str[i] == '%' && str[i - 1] != 92))
		{
			break;
		}
		else
		{
			count += write(1, &(str[i]), 1);
		}
		i++;
	}
	return (count);
}

/**
 * num_percent - findes the number of percentage signs in the string
 * @str: string
 * Return: count
 */

int num_percent(char *str)
{
	int count = 0, index = 0;

	while (str[index] != '\0')
	{
		if ((str[index] == '%' && str[index + 1] != '%')
				|| (str[index] == '%' && str[index - 1] != 92))
		{
			count++;
		}
		index++;
	}
	return (count);
}

