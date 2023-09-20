#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _atoi(char *s);

int main(int ac, char **av, char **env);
void prompt(void);
void handle(int signals);
void _EOF(char *buff);
void shell_exit(char **comm);

void child(char **comm, char *name, char **env, int cic);
int change_directory(const char *path);

void free_dp(char **comm);
void free_exit(char **comm);

char **token(char *buff, const char *s);

void execute(char **comm, char *name, char **env, int cic);
void print_env(char **env);
char **_getPath(char **env);
void msgERROR(char *name, int cic, char **comm);
#endif /* _MAIN_H_ */
