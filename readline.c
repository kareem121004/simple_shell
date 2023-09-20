#include "main.h"

/**
 * readline - read line
 * Return: buffer
*/
char *readline(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	int num_chars;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	num_chars = getline(&buffer, &buffer_size, stdin);

	if (num_chars == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
