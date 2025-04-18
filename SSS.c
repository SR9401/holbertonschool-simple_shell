#include "main.h"

int main(void)
{
	extern char **environ;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int w;
while (1)
{
		printf("$ ");

		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			free(line);
			break;
		}
		if (read <= 1)
		{
			continue;
		}

		char **args = split_string(line);
		pid = fork();

			if(pid == 0)
			{
				execve(args[0], args, environ);
			}
			else if (pid == -1)
			{
				perror("pp");
			}
			else
			{
				wait(&w);
			}

		(void)read;
}
}
