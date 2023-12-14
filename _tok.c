#include "main_shell.h"

/**
 * _tok - tokenizer
 * @input: param
 * @arg: param
 * Return: Success
 */

int _tok(char *input, char *arg[])
{
	int count;
	char *tokenizer = strtok(input, " ");

	if (tokenizer == NULL)
	{
		return (0);
	}
	count = 0;
	while (tokenizer != NULL && count < ARG_COUNT - 1)
	{
		arg[count++] = tokenizer;
		tokenizer = strtok(NULL, " ");
	}
	arg[count] = NULL;
	return (count);
}
