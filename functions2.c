#include "shell.h"
/**
* fullPath - A function that returns the path
* @command: the command we search its path
* Return: a string wich is the path
*/
char *fullPath(char *command)
{
extern char **environ;
 char *dir, *fullpath, *paths, *path = _getenv("PATH");
struct stat buff;
int i = 0;
char *name;

if (path == NULL)
{
perror("not found\n");
return (NULL);
}
while (environ[i] != NULL)
{
name = strtok(environ[i], "=");
if (_strcmp(name, "PATH") == 0)
break;
i++;
}
path = strtok(NULL, "=");
if (path)
{
dir = strtok(path, ":");
while (dir != NULL)
{
fullpath = malloc(_strlen(dir) + _strlen(command) + 2);
if (fullpath == NULL)
{
perror("malloc error");
exit(EXIT_FAILURE);
}
_strcpy(fullpath, dir);
_strcat(fullpath, "/");
_strcat(fullpath, command);
if (stat(fullpath, &buff) == 0)
{
paths = _strdup(fullpath);
free(fullpath);
return (paths);
}
else
{
free(fullpath);
dir = strtok(NULL, ":");
}
}
if (stat(command, &buff) == 0)
{
return (command);
}
return (NULL);
}
return (NULL);
}
/**
* pathexist - A function that checks if a path exists
* @command: the command we search its path
* Return: an int if its true or false
*/
int pathexist(char *command)
{
char *paths1;
char *path;
char *dir;
char *place;
struct stat statbuff;
path = _getenv("PATH");

if (path)
{
paths1 = _strdup(path);
dir = strtok(paths1, ":");
while (dir != NULL)
{
        place = malloc(_strlen(dir) + _strlen(command) + 2);
        _strcpy(place, dir);
        _strcat(place, "/");
        _strcat(place, command);

        if (stat(place, &statbuff) == 0)
        {
                free(paths1);
                free(place); /* je teste ici free */
                return (0);
        }
        else
        {
                free(place);
                dir = strtok(NULL, ":");
        }
}
free(paths1);
if (stat(command, &statbuff) == 0)
{
return (0);
}
return (1);
}
return (1);
}
/**
* _getenv - A function that return the environment
* @name: name of the environ
* Return: the environment
*/
char *_getenv(const char *name)
{
  extern char **environ;
while (*environ != NULL)
{
char *entry = *environ;
while (*entry != '=' && *entry != '\0')
{
entry++;
}
if (*entry == '=')
{
*entry = '\0';
if (_strcmp(name, *environ) == 0)
{
*entry = '=';
return (entry + 1);
}
*entry = '=';
}
environ++;
}
return (NULL);
}
/**
 * _env - Prints the environment
 */
void _env(void)
{
extern char **environ; 
int i;
for (i = 0; environ[i] != NULL; i++)
{
write(1, environ[i], _strlen(environ[i]));
write(1, "\n", 1);
}
}
/**
* intToStr - a function that converts an int to string
*/
void intToStr(int num, char *str)
{
    int i = 0, temp, length = 0;
    temp = num;

    while (temp != 0) {
        length++;
        temp /= 10;
    }

    for (i = 0; i < length; i++) {
        str[length - i - 1] = num % 10 + '0';
        num /= 10;
    }
    str[length] = '\0';
}
