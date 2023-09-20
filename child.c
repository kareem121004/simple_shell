#include "main.h"

/**
* child - to create subprocess
* @comm: pointer
* @name: pointer
* @env: pointer
* @cic: integer
* Return: void
*/

void child(char **comm, char *name, char **env, int cic)
{
	int pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_exit(comm);
	}
	else if (pid == 0)
	{
		execute(comm, name, env, cic);
		free_dp(comm);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
		free_exit(comm);
		}
		free_dp(comm);
	}
}
