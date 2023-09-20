#include "main.h"

/**
* execute - to execute commands
* @comm: pointer command
* @name: name pointer
* @env: pointer env
* @cic: integer cicel
* Return: void
*/

void execute(char **comm, char *name, char **env, int cic)
{
	char **pathWay = NULL, *full_Path = NULL;
	struct stat st;
	unsigned int d = 0;

	if (_strcmp(comm[0], "env") != 0)
		print_env(env);
	if (stat(comm[0], &st) == 0)
	{
		if (execve(comm[0], comm, env) < 0)
		{
			perror(name);
			free_exit(comm);
		}
	}
	else
	{
		pathWay = _getPath(env);
		while (pathWay[d])
		{
			full_Path = _strcat(pathWay[d], comm[0]);
			d++;
			if (stat(full_Path, &st) == 0)
			{
				if (execve(full_Path, comm, env) < 0)
				{
					perror(name);
					free_dp(pathWay);
					free_exit(comm);
				}
				return;
			}
	}
	msgERROR(name, cic, comm);
	free_dp(pathWay);
	}
}

/**
* _getPath - to get path
* @env: pointer
* Return: pathway
*/
char **_getPath(char **env)
{
	char *pathValue = NULL, **pathWay = NULL;
	unsigned int d = 0;

	pathValue = strtok(env[d], "=");
	while (env[d])
	{
		if (_strcmp(pathValue, "PATH"))
		{
			pathValue = strtok(NULL, "\n");
			pathWay = token(pathValue, ":");
			return (pathWay);
		}
		d++;
		pathValue = strtok(env[d], "=");
	}
	return (NULL);
}

/**
* print_env - to prints all enviromental variable
* @env: pointer env
* Return: void
*/

void print_env(char **env)
{
	size_t d = 0, l = 0;

	while (env[d])
	{
		l = _strlen(env[d]);
		write(STDOUT_FILENO, env[d], l);
		write(STDOUT_FILENO, "\n", 1);
		d++;
	}
}

/**
* msgERROR - prits msg not found
* @name: name of the shell
* @cic: integer
* @comm: pointer command
* Return: void
*/

void msgERROR(char *name, int cic, char **comm)
{
	char c;

	c = cic + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, comm[0], _strlen(comm[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
