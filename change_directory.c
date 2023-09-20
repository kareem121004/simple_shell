#include "main.h"

/**
* change_directory - changing the current directory to another directory
* @path: new directoty created
* Return: 0 or 1
*/

int change_directory(const char *path)
{
	char *bu = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(bu, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}
