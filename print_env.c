#include "shell.h"

/**
*print_env - functions for print env
*
*Return: always void
**/

void print_env(void)
{
char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
