#include "main_shell.h"

/**
 * _path - gets path of command
 * @input: param
 * Return: Nothing
 */

void _path(char **input)
{
	char *i, *j, *dir, *string_dup;

	i = NULL;
	j = NULL;

	if (input == NULL || *input == NULL)
	{
		return;
	}
	if (strchr(*input, '/') != NULL)
	{
		return;
	}
	dir = getenv("PATH");
	if (dir == NULL)
		return;
	string_dup = strdup(dir);
	i = strtok(string_dup, ":");
	while (i != NULL)
	{
		j = malloc(sizeof(char) * (_strlen(*input) + _strlen(i) + 2));
		if (j == NULL)
		{
			fprintf(stderr, "Failed\n");
			return;
		}
		sprintf(j, "%s/%s", i, *input);
		if (access(j, X_OK) == 0)
		{
			free(*input);
			*input = strdup(j);
			free(j);
			break;
		}
		free(j);
		i = strtok(NULL, ":");
	}
	free(string_dup);
}


/**
 * _strlen - string lenth
 * @string: the string
 * Return: 0;
 */

size_t _strlen(char *string)
{
	size_t i = 0;

	if (!string)
	{
		return (0);
	}
	while (*string++)
		i++;
	return (i);
}
