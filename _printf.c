#include "main_shell.h"

/**
 * printConsole - main print function
 * @input: string
 */

void printConsole(char *input)
{
	size_t len = _strlen(input);

	write(STDOUT_FILENO, input, len);
}
