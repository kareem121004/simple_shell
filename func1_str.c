#include "main.h"

/**
* _strlen - a length of string
* @s: string
* Return: count length of string
*/

int _strlen(char *s)
{
	unsigned int count = 0;

	while (s[count])
		count++;
	return (count);
}

/**
 * _strcmp - a function that compares two strings
 * @s1: Pointer to the destination string.
 * @s2: Pointer to the source string to be compared.
 * Return: 1 or 0
*/

int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

/**
 * *_strcat - a function that concatenates two strings
 * @dest: is the char to be checked
 * @src: is the char to be checked
 * Return: tmp
*/

char *_strcat(char *dest, char *src)
{
	char *tmp = dest;

	while (*dest)
		dest++;

	*dest++ = '/';
	while (*src)
		*dest++ = *src++;
	return (tmp);
}
