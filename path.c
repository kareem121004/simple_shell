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
	int i = 0;
	struct stat st;


	while (command[i])
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
			{
				return (_strdup(command));
			}
			return (NULL);
		}
		i++;
	}

	path = _getenv("PATH");

	if (!path)
	{
		return (NULL);
	}
	token = strtok(path, ":");

	while (token)
	{
		cmd = malloc(_strlen(token) + _strlen(command) + 2);
		if (cmd)
		{
			_strcpy(cmd, token);
			_strcat(cmd, "/");
		        _strcat(cmd, command);
			if (stat(cmd, &st) == 0)
			{
				free(path);
				return (cmd);
			}
			free(cmd), cmd = NULL;
		    token = strtok(NULL, ":");
		}
	}	
	free(path);
	return (NULL);
}
