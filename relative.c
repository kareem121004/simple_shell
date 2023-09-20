#include "main.h"

/**
* prompt - prints prompt
* Return: void
*/

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Hola_Shell>> ", 13);
}

/**
* handle - handle signals and path
* @signals: handling
* Return: nothing
*/

void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\nHola_Shell>>", 14);
}

/**
* _EOF - checks if buff is EOF
* @buff: pointer
* Return: nothing
*/

void _EOF(char *buff)
{
	if (buff)
	{
		free(buff);
		buff = NULL;
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buff);
	exit(EXIT_SUCCESS);
}

/**
* shell_exit - exit to exit from command
* @comm: command
* Return: nothing
*/

void shell_exit(char **comm)
{
	int exit_status = 0;

	if (comm[1] != NULL)
	{
		exit_status = _atoi(comm[1]);

	}
	free_dp(comm);
	exit(EXIT_SUCCESS);
}
