#include "shell.h"
/**
 * execute_command - Creates a child process to execute a command.
 *
 * This function forks a child process and uses the `execve` system call
 * to execute the command specified by `full_path` with the provided arguments.
 * The parent process waits for the child process to complete before
 * continuing.
 * @argv: An array of strings representing the command and its arguments.
 * @full_path: The full path to the executable command to be run.
 *
 * Return: None. The child process is responsible for executing
 * the command, and the parent process waits for the child to finish.
 */
void execute_command(char **argv, const char *full_path)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}

	if (pid == 0)
	{
		execve(full_path, argv, environ);
		perror("execve");
		exit(1);
	}
	else
	{
		wait(&status);
	}
}
