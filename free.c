#include "main.h"

void freearr(char **arr)
{
    int i = 0;
    
    if (!arr)
    {
        return; 
    }
    while (arr[i] != NULL)
    {
        free(arr[i]); 
        arr[i] = NULL;
        i++;
    }
    free(arr), arr = NULL;
    
}
