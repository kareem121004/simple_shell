#include "main.h"

/**
* check - checks a character in the string
* @c: character
* @str: string to check
* Return: 1 if succes, orherwise 0
*/

unsigned int check(char c, const char *str)
{
	unsigned int d;

	for (d = 0; str[d] != '\0'; d++)
	{
		if (c == str[d])
			return (1);
	}
	return (0);
}

/**
* _strork - take a string into token
* @str: string
* @ch: deli
* Return: pointer or null
*/

char *_strork(char *str, const char *ch)
{
	unsigned int d;
	static char *cl;
	static char *na;

	if (str != NULL)
		na = str;
	cl = na;
	if (cl == NULL)
		return (NULL);

	for (d = 0; cl[d] != '\0'; d++)
	{
		if (check(cl[d], ch) == 0)
		break;
	}
	if (na[d] == '\0' || na[d] == '#')
	{
		na = NULL;
		return (NULL);
	}
	cl = na + d;
	na = cl;
	for (d = 0; na[d] != '\0'; d++)
	{
		if (check(na[d], ch) == 1)
		break;
	}
	if (na[d] == '\0')
		na = NULL;
	else
	{
		na[d] = '\0';
		na = na + d + 1;
		if (*na = '\0')
			na = NULL;
	}
	return (cl);
}
