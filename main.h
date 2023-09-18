#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

extern char **environ;

void execute(char **args);
char *_strdup(const char *str);
char **_split(char *buffer, char *del);
char *_getenv(const char *name);
char *get_path(char *command);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
unsigned int check(char c, const char *str);
char *_strtok(char *str, const char *ch);
#endif
