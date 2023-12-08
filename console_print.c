#include "main_shell.h"

/**
 * printConsole - print to standard Output
 * @output: command to print
 */

void printConsole(char *output)
{
	write(STDOUT_FILENO, output, strlen(output));
}
