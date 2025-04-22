#include "shell.h"
/**
 * split_string - Function that splits a string and returns
 * an array of each word of the string.
 * @str: It's a pointer that pointe a string.
 * @delim: It's a pointer that pointer a char
 * that delimite the string at splits.
 * Return: return char in end.
 */
char **split_string(char *str, const char *delim)
{
	size_t capacity = 10;
	char *copy_str = strdup(str);
	char *token = strtok(copy_str, delim);
	char **result = malloc(capacity * sizeof(char *));
	size_t count = 0;
	char **result_tmp;

	if (result == NULL || copy_str == NULL)
	{
		free(result);
		free(copy_str);
		return (NULL);
	}

	for (; token != NULL ;)
	{
		if (count == capacity)
		{
			capacity *= 2;
			result_tmp = realloc(result, capacity * sizeof(char *));
			if (result_tmp == NULL)
			{
				free(result);
				free(copy_str);
				return (NULL);
			}
			result = result_tmp;
		}
		result[count++] = strdup(token);
		token = strtok(NULL, delim);

	}
	result[count] = NULL;
	free(copy_str);
	return (result);
}
