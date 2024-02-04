#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/**
 * print_digit - print a digit
 * @num: digit to print
 * @count: number of digit print
 *
 * Return: number of count
 */
int print_digit(int num)
{
	char *ptr;
	int count = 0, temp, i, j, len = 0;
	/* check if number is negative */
	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}
	/* check if num is equal to zero */
	if (num == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		/* convert num to ascii and print */
		temp = num;
		/* get length of num */
		while (temp > 0)
		{
			temp /= 10;
			len++;
		}
		/* dynamically allocate memory */
		ptr = (char *) malloc(sizeof(char) * len);
		if (ptr == NULL)
		{
			return (-1);
		}
		/* store each digit to the buffer */
		i = 0;
		while (num > 0)
		{
			ptr[i] = num % 10 + '0';
			num /= 10;
			i++;
		}
		j = i - 1;
		/* print digit store in the buffer */
		while (j >= 0)
		{
			_putchar(ptr[j]);
			j--;
			count++;
		}
	}
	return (count);
}
