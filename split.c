#include "main.h"

/**
 * _split - Splits a string
 * @buffer: The string
 * Return: divided path
*/
char **_split(char *buffer)
{
    char *tmp = NULL;
    char **arr = NULL;
    char *token;
    int i = 0, l = 0;

    if (!buffer)
    {
        return (NULL);
    }

    tmp = _strdup(buffer);
    token = strtok(buffer, del);

    if (token == NULL)
    {
        free(tmp), tmp = NULL;
        free(buffer), buffer = NULL;
        return (NULL);
    }

    while (token)
    {
        l++;
        token = strtok(NULL, del);
    }
    free(tmp), tmp = NULL;

    arr = malloc(sizeof(char *) * (l + 1));

    if (!arr)
    {
        free(buffer);
        return (NULL);
    }

    token = strtok(buffer, del);

    while (token)
    {
        arr[i] = _strdup(token);
        token = strtok(NULL, del);
        i++;
    }
    free(buffer), buffer = NULL;
    arr[i] = NULL;
    return(arr);
}
