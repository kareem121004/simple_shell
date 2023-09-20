#include "main.h"

char *readline(void)
{
    char *buffer = NULL;
    size_t buffer_size = 0;
    int num_chars;

    if (isatty(0))
        write(1, "$ ", 2);

    num_chars = getline(&buffer, &buffer_size, stdin);

    if (num_chars == -1)
    {
        free(buffer);
        return (NULL);
    }

    return (buffer);
}
