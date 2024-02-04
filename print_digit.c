#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/**
 * print_digit - print a digit
 * @num: digit to print
 *
 * Return: number of count
 */
int print_digit(int num)
{
	char *ptr;
	int count = 0, temp = num, i = 0, j, len = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}
	if (num == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (temp > 0)
		{
			temp /= 10;
			len++;
		}
		ptr = (char *) malloc(sizeof(char) * len);
		if (ptr == NULL)
			return (-1);
		while (num > 0)
		{
			ptr[i] = num % 10 + '0';
			num /= 10;
			i++;
		}
		j = i - 1;
		while (j >= 0)
		{
			_putchar(ptr[j]);
			j--;
			count++;
		}
	}
	return (count);
}
