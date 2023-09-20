#include "main.h"

/**
* main - A entry point
* @ac: input
* @av: pointer to array
* @env: pointer to array
* Return: 0
*/

int main(int ac, char **av, char **env)
{
	char *buff = NULL, **comm = NULL;
	size_t buf_size = 0;
	ssize_t chars_readed = 0;
	int cic = 0;
	(void)ac;

	while (1)
	{
		cic++;
		prompt();
		signal(SIGINT, handle);
		chars_readed = getline(&buff, &buf_size, stdin);
		if (chars_readed == EOF)
			_EOF(buff);
		else if (*buff == '\n')
			free(buff);
		else
		{
			buff[_strlen(buff) - 1] = '\0';
			comm = token(buff, " \0");
			free(buff);
			if (_strcmp(comm[0], "exit") != 0)
				shell_exit(comm);
			else if (_strcmp(comm[0], "cd") != 0)
				change_directory(comm[1]);
			else
				child(comm, av[0], env, cic);
		}
		fflush(stdin);
		buff = NULL, buf_size = 0;
	}
	if (chars_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
