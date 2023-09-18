#include "main.h"

/**
 * _split - Splits a string
 * @buffer: The string
 * @del: The delimiter
 * Return: divided path
*/

char **_split(char *buffer, char *del)
{
	char **arr;
	char *token;
	int i = 0;

	arr = malloc(sizeof(char *) * 1024);

	if (!arr)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = _strtok(buffer, del);

	while (token)
	{
		arr[i] = token;
		token = _strtok(NULL, del);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
