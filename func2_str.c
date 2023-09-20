#include "main.h"

/**
* _strcpy - copy two strings
* @dest: str
* @src: str
* Return: dest
*/

char *_strcpy(char *dest, char *src)
{
	char *aux = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (aux);
}

/**
 * _atoi - converts string to integer
 * @s: input.
 * Return: sum
*/

int _atoi(char *s)
{
	int si = 1;
	unsigned int sum = 0;
	char n_flag = 0;

	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == '-')
			si *= -1;
		if (*s >= '0' && *s <= '9')
		{
			n_flag = 1;
			sum = sum * 10 + (*s - '0');
		}
		else if (*s < '0' || *s > '9')
		{
			if (n_flag == 1)
				break;
		}
		s++;
	}
	if (si < 0)
		sum = (-1 * (sum));
	return (sum);
}
