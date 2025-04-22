#include "shell.h"
/**
 * main - Entry point for a simple shell.
 *
 * Displays a prompt, reads user input, tokenizes the input,
 * and executes the command using get_path. Supports the "exit"
 * command to terminate the shell gracefully.
 * @ac: Argument count (unused).
 * @av: Argument vector (used to get program name).
 * Return: Always returns 0.
 */


int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	char *argv[10];
	char *name = av[0];
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
		}
		if (getline(&line, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				printf("\n");
			}
			free(line);
			return (0);
		}
		arg(line, argv);
		if (argv[0] == NULL)
		{ continue; }
		if (strcmp(argv[0], "exit") == 0)
		{
			free(line);
			return (0);
		}
		get_path(line, argv, name);
	}
	free(line);
	return (0);
}

