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
* _strspn - length of prefix string
* @s: intial str
* @c: bytes
* Return: number
*/

int _strspn(char *s, char *c)
{
	int a, e, d;

	for (a = 0; *(s + a) != '\0'; a++)
	{
		d = 1;
		for (e = 0; *(c + e) != '\0'; e++)
		{
			if (*(s + a) == *(c + e))
			{
				d = 0;
				break;
			}
		}
		if (d == 1)
		break;
	}
	return (a);
}

/**
* _strchr - a character in string
* @s: string
* @c: character
* Return: pointer
*/

char *_strchr(char *s, char c)
{
	unsigned int i;

	for (i = 0; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);

	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
