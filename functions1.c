#include "shell.h"
/**
* _strlen - A function that returns a string length
* @s: the string we'll use
* Return: an int, number of characters of the string
*/
int _strlen(char *s)
{
int i;
i = 0;

while (s[i] != '\0')
{
i++;
}
return (i);
}
/**
* _strcpy - A function that copies a string into another
* @dest: the string that will be created
* @src: the string we'll copy
* Return: a string, the one copied
*/
char *_strcpy(char *dest, char *src)
{
int i, j, len;
i = 0;
while (src[i] != '\0')
{
i++;
}
len = i;
for (j = 0; j < len; j++)
{
dest[j] = src[j];
}
dest[j] = '\0';
return (dest);
}
/**
* _strcat - A function that concatenates two strings
* @dest: the string that will be created
* @src: the string we'll copy
* Return: a string, the fusion of both strings
*/
char *_strcat(char *dest, char *src)
{
int i, j, len;
i = 0;
j = 0;
while (dest[i] != '\0')
{
i++;
}
len = i;
while (src[j] != '\0')
{
dest[len] = src[j];
j++;
len++;
}
dest[len] = '\0';
return (dest);
}
/**
* _strcmp - A function that compares two strings
* @s1: the first string we want to compare
* @s2: the second string we want to compare
* Return: an int, 0 if the strings are the same
*/
int _strcmp(const char *s1, const char *s2)
{
while (*s1 == *s2)
{
if (*s1 == '\0')
{
return (0);
}
s1++;
s2++;
}
return (*s1 - *s2);
}
/**
* _strdup - A function that duplicates a string
* @str: the string we want to duplicate
* Return: the duplicated string
*/
char *_strdup(const char *str)
{
int i;
int j;
char *dup;
i = 0;

while (str[i] != '\0')
{
i++;
}
dup = malloc(i + 1);

if (dup == NULL)
{
perror("malloc error");
exit(EXIT_FAILURE);
}
for (j = 0; j < i; j++)
{
dup[j] = str[j];
}
dup[i] = '\0';
return (dup);
}
