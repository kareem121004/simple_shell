#include "main.h"

/**
 * _split - Splits a string
 * @buffer: The string
 * @del: The delimiter
 * Return: divided path
*/

char **_split(char *buffer, char *del)
{
    char **arr = NULL;
    char *tmp = NULL;
    char *token = NULL;
    int i = 0, j = 0;

    if (buffer == NULL || del == NULL)
    {
        return NULL;
    }

    tmp = _strdup(buffer);

    if (!tmp)
    {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    token = strtok(tmp, del);

    while (token)
    {
        i++;
        token = strtok(NULL, del);
    }

    free(tmp); 

    arr = malloc(sizeof(char *) * (i + 1));

    if (!arr)
    {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    tmp = _strdup(buffer);
    token = strtok(tmp, del);
    i = 0;

    while (token)
    {
        arr[i] = _strdup(token);

        if (!arr[i])
        {
            perror("malloc");
            for (j = 0; j < i; j++)
            {
                free(arr[j]);
            }
            free(arr);
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, del);
        i++;
    }

    free(tmp); 
    arr[i] = NULL; 

    return arr;
}
