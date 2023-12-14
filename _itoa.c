#include "main_shell.h"

/**
 * itoa - main function to convert integers to strings
 * @val: value
 * @str: string to convert
 * @size: size of char
 */

void itoa(int val, char *str, size_t size)
{
	int temp = val;
	size_t len = 0;

	if (size == 0)
	{
		return;
	}
	do {
		temp /= 10;
		len++;
	} while (temp > 0);
	if (len + 1 > size)
	{
		exit(EXIT_FAILURE);
	}
	temp = val;
	str[len] = '\0';
	do {
		str[--len] = temp % 10 + '0';
		temp /= 10;
	} while (temp > 0);
}

/**
 * _strlen - calculates the length of a string
 * @str: string to check
 * Return: len
 */

size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
