#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

int _strlen(char *s);
char *_strcpy(char *str, char *src, int n);
int _strcmp(char *a1, char *a2);
char *_strcat(char *dest, const char *src);
int _strspn(char *s, char *c);
char *_strchr(char *s, char c);

#endif
