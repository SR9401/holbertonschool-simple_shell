#include "shell.h"
/**
 * free_token - Frees a NULL-terminated array of strings.
 * @token: The array of strings to be freed.
 *
 * This function iterates through a NULL-terminated array of dynamically
 * allocated strings, frees each string, and then frees the array itself.
 * 
 * Return: 0 on success, 1 if the input is NULL.
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