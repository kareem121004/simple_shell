#include "main.h"

/**
 * execute - Executes a child process
 * @args:  An array of strings
 * @argv: argument
 * Return: 0
*/

int execute(char **args, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(argv[0]);
			freearr(args);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		freearr(args);
	}
	return (WEXITSTATUS(status));
}
