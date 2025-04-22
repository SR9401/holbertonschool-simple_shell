#include "shell.h"

/**
*print_env - functions for print env
*
*Return: always 0
**/

int print_env(void)
{
int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
return (0);
}
