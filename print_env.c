#include "shell.h"

/**
*print_env - functions for print env
*
*Return: always void
**/

void print_env(void)
{
int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
