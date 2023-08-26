#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints the binary representation of a number
 * @n: the decimal number
 * You are not allowed to use arrays
 * You are not allowed to use malloc
 * You are not allowed to use the % or / operators
 * Return: count
 */

int print_binary(unsigned long int n)
{
	int count = 0;

	if (n != 0)
	{
		if (n >> 1)
			print_binary(n >> 1);
		count += _putchar((n & 1) + '0');
	}
	else
		count += _putchar('0');
	return (count);
}
