#ifndef __HOLBERTON_H__
#define __HOLBERTON_H__
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
typedef struct bui
{   
	char *name;
	int (*f)(void);
}bui;
void _prompt(void);
int _strlen(char *s);
int _strlen_const(const char *s);
int _putchar(char c);
int _putstr(char *s);
char *_concat(char *src, char *dest);
char **parseintab(char *str);
int child_process(char **argv, char **env);
int _ischar(char c);
int nb(char *str, char *d);
int getnbwords(char *str, char *d);
char *_getenv(const char *name);
extern char **environ;
int _strncmp(const char *s1, char *s2, int nb);
char *parsePATH(char *cmd);
int _checkbuiltin(bui *b1, char *s);
int _launchbuiltin(bui *b1, char *s);
int exit_process();
#endif
