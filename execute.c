#include "main.h"

/**
 * execute - Executes a child process
 * @args:  An array of strings
*/

void execute(char **args)
{
	pid_t pid;
	int status;
	char *cmd;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		cmd = get_path(args[0]);

		if (cmd)
		{
			execve(cmd, args, environ);
		}
		else
			write(STDOUT_FILENO, "Invalid Command\n", 16);
		free(cmd);
		exit(0);
	}
	else
		wait(&status);
}
