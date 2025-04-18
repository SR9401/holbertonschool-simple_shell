#include "main.h"

char **split_string(const char *str)
{
    if (str == NULL)
        return NULL;

    char *copy = strdup(str);
    if (copy == NULL)
	return (NULL);

    int count = 0;
    char *token = strtok(copy, " ");
    while (token != NULL)
	{
        count++;
        token = strtok(NULL, " ");
    }

    char **result = malloc((count + 1) * sizeof(char *));
    if (result == NULL)
	{
        free(copy);
        return NULL;
    }

	strcpy(copy, str);
    token = strtok(copy, " ");
	for (int i = 0; token; i++)
	{
        result[i] = strdup(token);
        token = strtok(NULL, " ");
    }
    result[count] = NULL;

	free(copy);
    return result;
}
