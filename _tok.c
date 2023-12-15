#include "main_shell.h"

/**
 * _tok - main tokenizer function
 * @string: first param
 * @del: delimeter
 * Return: string
 */

char **_tok(char *string, const char *del)
{
	char **input = NULL, *tok;
	char *string_dup;
	size_t num, i;

	if (string == NULL || *string == '\0')
		return (NULL);
	string_dup = strdup(string);
	tok = strtok(string_dup, del);
	num = 0;
	while (tok != NULL)
	{
		++num;
		tok = strtok(NULL, del);
	}
	free(string_dup);
	if (num > 0)
	{
		input = malloc(sizeof(char *) * (num + 1));
		if (input == NULL)
		{
			return (NULL);
		}
		tok = strtok(string, del);
		i = 0;
		while (tok != NULL)
		{
			input[i++] = strdup(tok);
			tok = strtok(NULL, del);
		}
		input[i] = NULL;
	}
	return (input);
}
