#include "main.h"


/**
 * _getenv - retrieves the value of an environment
 * @name: the name of the environment variable to retrieve
 * Return: the value of the environment variable
*/


char *_getenv(const char *name)
{
	int i = 0;
	char *token;

	while (environ[i])
	{
		token = strtok(environ[i], "=");

		if (_strcmp(name, token) == 0)
			return (strtok(NULL, "\n"));
		i++;
	}
	return (NULL);
}
