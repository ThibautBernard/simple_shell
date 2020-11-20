#ifndef __HOLBERTON_H__
#define __HOLBERTON_H__
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
typedef struct env
{
	char *str;
	struct env *next;
}envNodes;
typedef struct bui
{
	char *name;
	int (*f)(int, char **, envNodes **);
}bui;
char *_strtok(char *str, const char *delim);
void _prompt(envNodes *env);
int _strlen(char *s);
int _strlen_const(const char *s);
int _putchar(char c);
int _putstr(char *s);
int print_env(int n, char **s, envNodes **env);
char *_concat(char *src, char *dest, char delim);
char **parseintab(char *str);
char *_child_process(char **argv, char **env, envNodes *environ);
int _ischar(char c);
int exit_process(int nb, char **s, envNodes **env);
//int nb(char *str, char *d);
int getnbwords(char *str, char *d);
char *_getenv(const char *name, envNodes **env);
extern char **environ;
int _strncmp(const char *s1, char *s2, int nb);
char *parsePATH(char *cmd, envNodes **env);
int _checkbuiltin(bui *b1, char **s);
int _launchbuiltin(bui *b1, char **s, envNodes *env);
int freetab(char **tb);
envNodes *transformEnv(void);
envNodes *add_nodechar_end(envNodes **head, char *s);
int _setenv(int n, char **s, envNodes **env);
int _unsetenv(int n, char **s, envNodes **env);
#endif
