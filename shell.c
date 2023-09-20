#include "main.h"

/**
 * main - start
 * Description: simple shell
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
			if (isatty(0))
			{
				write(1, "\n", 1);
			}
			return (status);
		}

		args = _split(buffer, " \t\n");

		if (!args)
		{
			continue;
		}
		status = execute(args, argv);
	}
	free(buffer);
}
