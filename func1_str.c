#include "main.h"

/**
* _strlen - a length of string
* @s: string
* Return: count length of string
*/

int _strlen(char *s)
{
	int count;

	for (count = 0; *s != '\0'; s++)
	{
		count++;
	}
	return (count);
}

/**
 *  _strcmp - a function that compares two strings
 * @s1: Pointer to the destination string.
 * @s2: Pointer to the source string to be compared.
 * Return: Pointer to the resulting string (same as dest).
*/

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((int)(unsigned char)(*s1) - (int)(unsigned char)(*s2));
}

/**
 * *_strcpy - a function that copies the string pointed to by src
 * @dest: is the char to be checked
 * @src: is the char to be checked
 * Return: dest
*/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
