#include "main.h"

/**
* free_dp - free the memory
* @comm: pointer
*  Return: void
*/

void free_dp(char **comm)
{
	size_t d = 0;

	if (comm == NULL)
		return;

	while (comm[d])
	{
		free(comm[d]);
		d++;
	}

	if (comm[d] == NULL)
		free(comm[d]);
	free(comm);
}

/**
* free_exit - free memory
* @comm: pointer
* Return: void
*/

void free_exit(char **comm)
{
	size_t d = 0;

	if (comm == NULL)
		return;

	while (comm[d])
	{
		free(comm[d]);
		d++;
	}

	if (comm[d] == NULL)
		free(comm[d]);
	free(comm);
	exit(EXIT_FAILURE);
}
