#include "shell.h"
/**
 * 
 */

int free_token(char **token)
{
	int i;

	if (token == NULL)
	{
		return (1);
	}

	for (i = 0 ; token[i] != NULL ; i++)
	{
		free(token[i]);
	}
	free(token);
	return (0);
}