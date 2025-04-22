#include "shell.h"
/**
 * arg - Splits a string into tokens and stores them in an array.
 * This function removes the newline from the string and splits it into
 * tokens by spaces. It stores tokens in `argv` and null-terminates it.
 * @line: The input string to split.
 * @argv: The array to store the tokens.
 * Return: return void in end.
 */

void arg(char *line, char **argv)
{
	int i = 0;
	char *token;

	line[strcspn(line, "\n")] = 0;
		token = strtok(line, " ");

		for (; token != NULL && i < 10 ;)
		{
			argv[i++] = token;
			token = strtok(NULL, " ");
		}
		argv[i] = NULL;
}
