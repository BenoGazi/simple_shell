#include "main_shell.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: vector
 * Return: Always 0;
 */

int main(int argc, char *argv[])
{
	char *lpoint = NULL, **input = NULL;
	size_t i = 0, i_count = 0;
	ssize_t i_read;
	pid_t child;
	int stat, exit_stat;
	(void)argc;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			printConsole("$ ");
		fflush(stdout);
		i_read = getline(&lpoint, &i, stdin);
		++i_count;
		if (i_read == -1)
		{
			free(lpoint);
			lpoint = NULL;
			if (isatty(STDIN_FILENO))
				printConsole("\n");
			exit(0);
		}
		lpoint[i_read - 1] = '\0';
		if (*lpoint == '\0')
		{
			free(lpoint);
			lpoint = NULL;
			continue;
		}
		input = _tok(lpoint, " ");
		if (input == NULL || input[0] == NULL)
		{
			fprintf(stderr, "Error: Invalid Command\n");
			free(lpoint);
			lpoint = NULL;
			_free(input);
			continue;
		}
		if (access(input[0], X_OK) == -1)
		{
			_path(&input[0]);
			if (input != NULL && access(input[0], X_OK) == -1)
				fprintf(stderr, "%s: %lu: %s: not found\n", argv[0], i_count, input[0]);
					exit(127);
		}
		child = fork();
		if (child == -1)
		{
			perror("fork");
			free(lpoint);
			lpoint = NULL;
			_free(input);
			exit(EXIT_FAILURE);
		}
		if (child == 0)
		{
			if (execve(input[0], input, environ) == -1)
			{
				perror("execve");
				exit(126);
			}
		}
		else
		{
			waitpid(child, &stat, 0);
			if (WIFEXITED(stat))
			{
				exit_stat = WEXITSTATUS(stat);
				exit(exit_stat);
			}
		}
		free(lpoint);
		_free(input);
		input = NULL;
		lpoint = NULL;
	}
	return (0);
}
