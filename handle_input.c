#include "main_shell.h"

/**
 * _input - main function
 * @input: param 1
 * @size: param 2
 */

void _input(char *input, size_t size)
{
	size_t len = 0;
	pid_t _pid;

	fgets(input, size, stdin);

	while (input[len] != '\0' && input[len] != '\n')
	{
		len++;
	}
	if (input[len] == '\n')
	{
		input[len] = '\0';
	}
	_pid = fork();
	if (_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (_pid == 0)
	{
		char *args[ARG_COUNT];
		/*int arg_count = _tok(input, args);*/
		char *env[] = {NULL};

		execve(args[0], args, env);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
