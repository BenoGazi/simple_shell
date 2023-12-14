#include "main_shell.h"

/**
 * main - main function
 * @argc: Argument Count
 * @argv: Argument Vector
 * Return: Success
 */

int main(__attribute__((unused))int argc, char *argv[])
{
	char input[ARG_COUNT];
	char *output;
	size_t output_len;

	if (argc > 1)
	{
		handle_args(argc, argv);
		return (0);
	}
	do {
		printConsole("$");
		_input(input, sizeof(input));
		_output(&output, &output_len);
		printConsole(input);
		printConsole("\n");
		free(output);
	} while (true);
	return (0);
}

/**
 * handle_args - main function
 * @argc: count
 * @argv: vector
 */

void handle_args(int argc, char *argv[])
{
	char buffer[ARG_COUNT], idx[10];
	const char *sep = " ";
	const char *header = "";

	size_t idx_len = 0;
	size_t j = 0;
	int temp = 1;
	int i = 0;
	(void)argv;

	while (i < argc)
	{
		i++;
		header = " ";
		temp = 1;
		sep = " ";
		while (*header)
		{
			buffer[j++] = *header++;
		}
		do {
			idx[idx_len++] = temp % 10 + '0';
			temp /= 10;
		} while (temp > 0);
		while (idx_len > 0)
		{
			buffer[j++] = idx[--idx_len];
		}
		while (*sep)
		{
			buffer[j++] = *sep++;
		}
		buffer[j++] = '\n';
		write(STDOUT_FILENO, buffer, j);
		j = 0;

	}
}
