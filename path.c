#include "main_shell.h"

/**
 * _path - gets path of command
 * @input: param
 * Return: Nothing
 */

void _path(char **input)
{
	char *i, *j = NULL, *dir, *string_dup;
	char *mod_input;
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
	if (string_dup == NULL)
	{
		fprintf(stderr, "FAILED TO DUPLICATE\n");
		return;
	}
	i = strtok(string_dup, ":");
	while (i != NULL)
	{
		j = malloc(sizeof(char) * (_strlen(*input) + _strlen(i) + 2));
		if (j == NULL)
		{
			fprintf(stderr, "Failed\n");
			free(string_dup);
			return;
		}
		sprintf(j, "%s/%s", i, *input);
		if (access(j, X_OK) == 0)
		{
			mod_input = strdup(j);
			if (mod_input == NULL)
			{
				fprintf(stderr, "failed to duplicate mem");
				free(j);
				free(string_dup);
				exit(EXIT_FAILURE);
			}
			free(*input);
			*input = mod_input;
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
