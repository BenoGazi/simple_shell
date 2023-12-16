#ifndef MAIN_SHELL
#define MAIN_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

void _free(char **input);
char **_tok(char *string, const char *del);
void _path(char **input);
void printConsole(char *input);
int main(__attribute__((unused))int argc, char *argv[]);
char *strdup(const char *string);
char *_strtok(char *string, const char *del);
extern char **environ;
size_t _strlen(char *string);
char *_strcat(char *dest, char *n);
#endif
