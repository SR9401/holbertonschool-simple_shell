#include "shell.h"
/**
 * handle_sigint - Function that handler Crtl C signal.
 * @sig: The signal number (should be SIGINT).
 * This function is called automatically when the user presses Ctrl+C.
 * It prevents the shell from exiting and instead prints a new prompt.
 * The signal number is unused in this case.
 * Return: return void in end.
 */
void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

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

	signal(SIGINT, handle_sigint);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{	printf("$ "); }
		if (getline(&line, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
			{	printf("\n"); }
			free(line);
			return (0);
		}
		arg(line, argv);
		if (argv[0] == NULL)
		{ continue; }
		if (strcmp(argv[0], "exit") == 0)
		{
			if (argv[1] != NULL)
			{	fprintf(stderr, "%s: 1: %s: Illegal number: %s\n",
				name, argv[0], argv[1]);
				continue; }
			free(line);
			return (0); }
		if (strcmp(argv[0], "env") == 0)
		{
			print_env();
			continue;
		}
		get_path(argv[0], argv, name);
	}
	free(line);
	return (0);
}

