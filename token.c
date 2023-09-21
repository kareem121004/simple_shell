#include "main.h"

/**
* token - token to split
* @s: delimiter for strtok
* @buff: pointer buffer
* Return: string with comms
*/

char **token(char *buff, const char *s)
{
	char *tak = NULL, **comms = NULL;
	size_t bufsize = 0;
	int d = 0;

	if (buff == NULL)
		return (NULL);

	bufsize = _strlen(buff);
	comms = malloc((bufsize + 1) * sizeof(char *));
	if (comms == NULL)
	{
		perror("Unable to allocate buffer");
		free(buff);
		free_dp(comms);
		exit(EXIT_FAILURE);
	}
	tak = strtok(buff, s);
	while (tak != NULL)
	{
		comms[d] = malloc(_strlen(tak) + 1);
		if (comms[d] == NULL)
		{
			perror("Unable to allocate buffer");
			free_dp(comms);
			return (NULL);
		}
		_strcpy(comms[d], tak);
		tak = strtok(NULL, s);
		d++;
	}
	comms[d] = NULL;
	return (comms);
}
