#include "main_shell.h"

/**
 * _free - frees memory of token
 * @input: param 1
 * REturn: Nothing
 */

void _free(char **input)
{
	size_t i = 0;

	while (input[i] != NULL)
	{
		free(input[i]);
		input[i] = NULL;
		i++;
	}
	free(input);
}

/**
 * _strdup - duplicate string
 * @string: param 1;
 * Return: string;
 */

char *_strdup(const char *string)
{
	int len;
	const char *temp = string;
	char *i;
	int j = 0;

	if (string == NULL)
	{
		return (NULL);
	}
	while (*temp++)
	{
		len++;
	}
	i = malloc(sizeof(char) * (len + 1));
	if (i == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < len; j++)
	{
		i[j] = string[j];
	}
	i[len] = '\0';
	return (i);
}

/**
 * _strchr - main strchr
 * @string: param 1
 * @ch: param 2
 * Return: Success
 */

char *_strchr(const char *string, int ch)
{
	while (*string != '\0')
	{
		if (*string == ch)
		{
			return ((char *)string);
		}
		string++;
	}
	return (NULL);
}


/**
 * _strtok - tokenizer function
 * @string: string
 * @del: param 2
 * Return: Always 0;
 */

char *_strtok(char *string, const char *del)
{
	static char *tok;
	static char *n_tok;
	char *ch = n_tok;

	if (string != NULL)
	{
		tok = string;
		n_tok = tok;
	}
	else if (n_tok == NULL)
	{
		return (NULL);
	}
	while (*ch != '\0' && _strchr(del, *ch) != NULL)
	{
		ch++;
	}
	if (*ch != '\0')
	{
		*ch = '\0';
		n_tok = ch + 1;
	}
	else
		n_tok = NULL;
	return (tok);
}
