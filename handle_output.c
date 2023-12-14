#include "main_shell.h"

/**
 * _output - main function
 * @output: param 1
 * @len: param 2
 */

void _output(char **output, size_t *len)
{
	size_t length = 0, i = 0;
	char buffer[ARG_COUNT];
	char *args[ARG_COUNT];
	char *temp;
	int args_count = _tok(*output, args);
	*len = 0;

	temp = (char *)malloc(*len + length + 1);
	if (temp == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < *len; i++)
	{
		temp[i] = (*output)[i];
	}
	while (fgets(buffer, sizeof(buffer), stdin))
	{
		length = _strlen(buffer);
		for (i = 0; i < length; i++)
		{
			temp[*len + i] = buffer[i];
		}
		*len += length;
		temp[*len] = '\0';
		if (temp[*len - 1] == '\n')
		{
			temp[*len - 1] = '\0';
			printConsole("$ ");
			printConsole(temp);
			free(*output);
			*output = temp;
			for (i = 0; i < (size_t)args_count; i++)
			{
				free(args[i]);
			}
			break;
		}
	}
}
