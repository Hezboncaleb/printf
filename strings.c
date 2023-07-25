#include "main.h"

/**
 * copy_values - copies values from a const char pointer to a new char pointer
 * @format: const char pointer
 * @str: char pointer
 * @len: format length
 * Return: void
 */

void copy_values(const char *format, char *str, unsigned int len)
{
	unsigned int i = 0;

	while (i < len)
	{
		str[i] = format[i];
		i++;
	}
}

/**
 * _strlen - returns the length of a string.
 * @s: string to be used
 * Return: length of string
 */

int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
