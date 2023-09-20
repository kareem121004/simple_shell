#include "main.h"

/**
 * main - start
 * Description: simple shell
 * @argc: argc
 * @argv: argument
 * Return: 0
*/

int main(int argc, char **argv)
{
	char *buffer = NULL;
	int status = 0;
	char **args;
	(void) argc;

	while (1)
	{
		buffer = readline();
		if (buffer == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (status);
		}

		args = _split(buffer);

		if (!args)
			continue;
		else
			status = execute(args, argv);
	}
}
