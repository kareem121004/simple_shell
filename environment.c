#include "main.h"


/**
 * _getenv - retrieves the value of an environment
 * @name: the name of the environment variable to retrieve
 * Return: the value of the environment variable
*/


char *_getenv(const char *name)
{
	int i = 0;
	char *token, *env, *tmp, *val;

	while (environ[i])
	{
		tmp = _strdup(environ[i]);
		token = strtok(tmp, "=");

		if (_strcmp(name, token) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
		i++;
	}
	return (NULL);
}
