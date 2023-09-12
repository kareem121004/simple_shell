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
* _strcpy - copy string
* @str: string
* @src: string
* Return: pointer to src
*/
char *_strcpy(char *str, char *src, int n)
{
	int d = 0;

	while (d < n && src[d] != '\0')
	{
		str[d] = src[d];
		d++;
	}
	while (d > n)
	{
		str[d] != '\0';
		d++;
	}

	return (str);
}

/**
* _strcmp - compares between two strings
* @a1: string compared
* @a2: string compared
* Return: 0
*/

int _strcmp(char *a1, char *a2)
{
	int d;

	for (d = 0; a1[d] == a2[d] && a1[d]; d++)
		;

	if (a1[d] > a2[d])
		return (1);
	if (a1[d] < a2[d])
		return (-1);
	return (0);
		return (1);
}
