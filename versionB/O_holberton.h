#ifndef __HOLBERTON_H__
#define __HOLBERTON_H__
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void _prompt(void);
int _strlen(char *s);/**/
int _strlen_const(const char *s);
int _putchar(char c);/**/
int _putstr(char *s);/**/
char *_concat(char *src, char *dest);/**/
char **parseintab(char *str);
int child_process(char **argv, char **env);
int _ischar(char c);/**/
int nb(char *str, char *d);
int getnbwords(char *str, char *d);/**/
char *_getenv(const char *name);
extern char **environ;
int _strncmp(const char *s1, char *s2, int nb);/**/
/*O_parser*/
int _strlendelim(char *str, char *d);/**/
char **O_parseintab(char *str, char *d);/**/
void freetab(char **tb);/**/
char *_checkinpath(char *stcmd);/**/
int intcheckinpath(char *stcmd);/**/
int _exit1(void);/**/
int checkinbuiltin();/**/
char **O_getenv(char *envname);/**/
char *O_concat(char *s1, char *s2);/**/
/*O_shell*/
int launchfunction(char **tb);

#endif
