#include "shell.h"
/**
 * get_path - Searches for a command in the system's PATH and executes it.
 *
 * This function retrieves the PATH environment variable, splits it into
 * individual directories, and appends the command name to each directory
 * to construct a full executable path. If the command is found and is
 * executable, it is executed via execute_command().
 * If the command is not found in any PATH directory,
 * an error message is printed.
 *
 * @cmd: The name of the command to search for (e.g., "ls", "echo").
 * @argv: An array of strings representing the command and its arguments.
 *
 * Return: Always returns NULL.
 */
char **get_path(const char *cmd, char **argv)
{
	char *path = _getenv("PATH");
	char **token = split_string(path, ":");
	int i;
	char full_path[1024];

	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
		{
			execute_command(argv, cmd);
			return (NULL);
		}
	}
	if (path == NULL)
	{
		printf("PATH is empty!\n");
		return (NULL);
	}
	for (i = 0; token[i] != NULL; i++)
	{
		strcpy(full_path, token[i]);
		strcat(full_path, "/");
		strcat(full_path, cmd);
		if (access(full_path, X_OK) == 0)
		{
			execute_command(argv, full_path);
			return (NULL);
		}
	}
	if (access(full_path, X_OK) == -1)
	{
		printf("%s: command not found\n", cmd);
	}
	return (NULL);
}
