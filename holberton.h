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
extern char **environ;
/**
 * struct env - singly linked list
 * @str: string that environnement variables
 * @next: points to the next node
 * Description: singly linked list that store all the
 * environ
 */
typedef struct env
{
	char *str;
	struct env *next;
} envNodes;

/**
 * struct bui - struct
 * @name: name of the function to call
 * @f: pointer of function to call the function (name)
 * int, char ** (double array that store all the entry
 * of the user, @envNodes pointer of pointer that store
 * the adress of the linked list of environ
 * Description: to call builtin function
 */
typedef struct bui
{
	char *name;
	int (*f)(int, char **, envNodes **);
} bui;

/** parser.c **/
char **parseintab(char *str);
char *parsePATH(char *cmd, envNodes **env);

/** process.c **/
char *_child_process(char **argv, char **env, envNodes *environ);
int child_process_built(char **argv);

/** utilities.c **/
int _strncmp(const char *s1, char *s2, int nb);
int _strlen(char *s);
int _putchar(char c);
int _putstr(char *s);
char *_concat(char *src, char *dest, char delim);

/** prompt.c **/
void _prompt(envNodes *env);

/** _exit.c **/
int exit_process(int nb, char **s, envNodes **env);

/** checkbuiltin.c **/
int _checkbuiltin(bui *b1, char **s);
int _launchbuiltin(bui *b1, char **s, envNodes *env);

/** env.c **/
int _strlen_const(const char *s);
int _setenv(int n, char **s, envNodes **env);
int _unsetenv(int n, char **s, envNodes **env);
char *_getenv(const char *name, envNodes **env);
int print_env(int n, char **s, envNodes **env);

/** _strtok.c **/
char *_strtok(char *str, const char *delim);

/** getnbwords.c **/
int _ischar(char c);
int getnbwords(char *str, char *d);

/** arraytonodes.c **/
envNodes *add_nodechar_end(envNodes **head, char *s);
envNodes *transformEnv(void);

/** utilitiesfree.c **/
int freetab(char **tb);

/** _atoi.c **/
int _atoi(char *s);
int minus(char *c);

int check_sep(char **argv);

#endif
