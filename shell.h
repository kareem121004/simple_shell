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

#define del " \t\n"
extern char **environ;
void freearr(char **arr);
int execute(char **args, char **argv);
char *_strdup(const char *str);
char **_split(char *buffer);
char *_getenv(const char *name);
char *get_path(char *command);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
unsigned int check(char c, const char *str);
char *_strtok(char *str, const char *ch);
char *readline(void);
#endif
