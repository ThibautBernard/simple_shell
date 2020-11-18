#ifndef __HOLBERTON_H__
#define __HOLBERTON_H__
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
extern char **environ;

/*env.c*/
int _strlen_const(const char *s);
char *_getenv(const char *name);
int print_env(int n);

/*checkbuiltin.c*/
typedef struct bui
{   
	char *name;
	int (*f)(int);
}bui;

int _checkbuiltin(bui *b1, char *s);
int _launchbuiltin(bui *b1, char *s);

/*_exit.c*/
int exit_process(int nb);

/*getnbwords.c*/
int _ischar(char c);
int getnbwords(char *str, char *d);

/*parser.c*/
char **parseintab(char *str);
char *parsePATH(char *cmd);

/*process.c*/
int child_process(char **argv, char **env);
int child_process_built(char **argv);

/*prompt.c*/
void _prompt(void);

/*utilities.c*/
int _strncmp(const char *s1, char *s2, int nb);
int _strlen(char *s);
int _putchar(char c);
int _putstr(char *s);
char *_concat(char *src, char *dest);
/*shell.c MAIN*/
#endif
