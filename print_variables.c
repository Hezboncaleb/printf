#include "main.h"

/**
 * print_string - prints string in output
 * @str: string
 * Return: count
 */

int print_string(char *str)
{
	int count = 0, i = 0;

	while (str[i] != '\0')
	{
		count += _putchar(str[i]);
		i++;
	}
	return (count);
}
/**
 * print_int - prints an integer value
 * @n: integer value
 * Return: count
 */

int print_int(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}
	if (n / 10 != 0)
	{
		count += print_int(n / 10);
	}
	_putchar((n % 10) + '0');
	count++;

	return (count);
}

/**
 * print_unsignedint - prints an unsigned integer
 * @n: value to print
 * Return: number of bytes printed
 */
int print_unsignedint(int n)
{
	int count = 0;

	if (n < 0)
	{
		n *= -1;
	}
	if (n / 10 != 0)
	{
		count += print_unsignedint(n / 10);
	}
	_putchar((n % 10) + '0');
	count++;

	return (count);
}

/**
 * print_String - prints string in output
 * @str: string
 * Return: count
 */

int print_String(char *str)
{
	int count = 0, i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar('0');
			count += _putchar('A');
		}
		else
			count += _putchar(str[i]);
		i++;
	}
	return (count);
}
