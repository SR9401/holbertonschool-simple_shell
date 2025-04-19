#include "shell.h"
/**
 * _getenv - Retrieves the value of an environment variable.
 *
 * This function searches the environment variables for a variable
 * matching the given name and returns a newly allocated copy of its value.
 * @name: The name of the environment variable to search for (e.g., "PATH").
 *
 * Return: A pointer to a newly allocated string containing
 * the variable's value or NULL if the variable is not found.
 */
char *_getenv(const char *name)
{
	int i;
	char *copy = NULL;
	char *token, *value;

	for (i = 0 ; environ[i] != NULL ; i++)
	{
		copy = strdup(environ[i]);
		token = strtok(copy, "=");
		if (strcmp(name, token) == 0)
		{
			value = strdup(strtok(NULL, "="));
			free(copy);
			return (value);
		}
		free(copy);
	}
	return (NULL);
}
