#include "main.h"

/**
 * get_path - Searches for a command in the system's PATH
 * @command: The name of the command to search for
 * Return: A pointer to the full path
*/

char *get_path(char *command)
{
	char *path;
	char *token;
	char *cmd;
	struct stat st;

	if (command[0] == '/')
	{
		struct stat st;

		if (stat(command, &st) == 0)
			return (_strdup(command));
		else
			return (NULL);
	}

	path = _getenv("PATH");
	token = _strtok(path, ":");

	while (token)
	{
		cmd = malloc(_strlen(token) + _strlen(command) + 2);

		if (!cmd)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		_strcpy(cmd, token);
		_strcat(cmd, "/");
		_strcat(cmd, command);

		if (stat(cmd, &st) == 0)
			return (cmd);
		free(cmd);
		token = _strtok(NULL, ":");
	}
	return (NULL);
}
