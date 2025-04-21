#include "shell.h"
/**
 * main - Entry point for a simple shell.
 *
 * Displays a prompt, reads user input, tokenizes the input,
 * and executes the command using get_path. Supports the "exit"
 * command to terminate the shell gracefully.
 *
 * Return: Always returns 0.
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *argv[10];

	while (1)
	{
		printf("$ ");
		getline(&line, &len, stdin);
		arg(line, argv);

		if (argv[0] == NULL)
		{
			continue;
		}
		if (strcmp(argv[0], "exit") == 0)
		{
			free(line);
			return (0);
		}
		get_path(argv[0], argv);
	}
	free(line);
	return (0);
}
