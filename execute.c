#include "main.h"

/**
 * execute - Executes a child process
 * @args:  An array of strings
*/

int execute(char **args, char **argv)
{
	pid_t pid;
	int status;
	char *cmd;
	(void) argv;

	cmd = get_path(args[0]);
	if (!cmd)
	{
		write(STDOUT_FILENO, "Invalid Command\n", 16);
		freearr(args);
		return (127);
	}
	pid = fork();

	if (pid == 0)
	{
		if (execve(cmd, args, environ) == -1)
		{
			freearr(args);
			free(cmd), cmd = NULL;
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		freearr(args);
		free(cmd), cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
