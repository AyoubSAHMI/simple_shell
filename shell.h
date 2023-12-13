#ifndef SIMSH_H
#define SIMSH_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>/*zedt hadi*/

extern char **environ;

int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *fullPath(char *command);
int pathexist(char *command);
char *_strdup(const char *str);
char *_getenv(const char *name);
void _env(void);
void intToStr(int num, char *str);
#endif /*SIMSH_H*/
