#ifndef MAIN_SHELL
#define MAIN_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define ARG_COUNT 86
#define INPUT_COUNT 1024

void printConsole(char *output);
int _tok(char *input, char *arg[]);
int main(__attribute__((unused))int ac, char *av[]);
void _input(char *input, size_t size);
void _output(char **output, size_t *len);
void handle_args(int argc, char *argv[]);
size_t _strlen(const char *str);
void itoa(int val, char *str, size_t size);
#endif
