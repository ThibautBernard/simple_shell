#ifndef __HOLBERTON_H__
#define __HOLBERTON_H__
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
/*
typedef struct env
{   
	char *str;
	struct env *next;
}envNodes;*/
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
	//int (*f)(int, char **, envNodes **);
}bui;

//void _prompt(envNodes *env);
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
char *_child_process(char **argv, char **env);

/*prompt.c*/
void _prompt(void);

/*utilities.c*/
int _strncmp(const char *s1, char *s2, int nb);
int _strlen(char *s);
int _putchar(char c);
int _putstr(char *s);
int print_env(int n); //
//int print_env(int n, char **s, envNodes **env);
char *_concat(char *src, char *dest, char delim);
//char *_child_process(char **argv, char **env, envNodes *environ);
//int exit_process(int nb, char **s, envNodes **env);
int nb(char *str, char *d);
int getnbwords(char *str, char *d);
char *_getenv(const char *name); //
//char *_getenv(const char *name, envNodes *env);
extern char **environ;
int _strncmp(const char *s1, char *s2, int nb);
char *parsePATH(char *cmd); //
//char *parsePATH(char *cmd, envNodes *env);
//int _launchbuiltin(bui *b1, char **s, envNodes *env);
int freetab(char **tb);
//envNodes *transformEnv(void);
//envNodes *add_nodechar_end(envNodes **head, char *s);
int _setenv(int n, char **s); //
//int _setenv(int n, char **s, envNodes **env);

/* utilitiesfree.c*/
int freetab(char **tb);

/*shell.c MAIN*/

/*_strtok.c*/
char *_strtok(char *str, const char *delim);
#endif
