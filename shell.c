#include "main.h"

/**
 * main - start
 * Description: simple shell
 * Return: 0
*/

int main(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	int num_chars;
	char **args;

	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);

		num_chars = getline(&buffer, &buffer_size, stdin);

		if (num_chars == -1)
		{
			write(1, "\n", 1);
			free(buffer);
			exit(1);
		}

		args = _split(buffer, " \t\n");

		if (args[0] == NULL)
		{
			free(args);
			continue;
		}

		if (_strcmp(args[0], "exit") == 0)
		{
			free(buffer);
			free(args);
			exit(0);
		}

		execute(args);
		free(args);
	}
	free(buffer);
}
