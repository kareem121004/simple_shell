#include "main.h"

/**
* _strcat - concatenate two strings
* @dest: str
* @src: str
* Return: dest
*/

char *_strcat(char *dest, const char *src)
{
	int i, d;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (d = 0; src[d] != '\0'; d++)
	{
		dest[i] = src[d];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - Duplicate a string
 * @str: The source string to duplicate.
 * Return: A pointer to the newly duplicated string
*/

char *_strdup(const char *str)
{
	char *dup;
	int i = 0, len = 0;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;

	dup = malloc(sizeof(char *) * (len + 1));

	if (dup != NULL)
	{
		for (i = 0; i < len; i++)
		{
			dup[i] = str[i];
		}
		dup[len] = '\0';
	}

	return (dup);
}
