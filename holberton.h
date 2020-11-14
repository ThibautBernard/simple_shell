#ifndef __HOLBERTON_H__
#define __HOLBERTON_H__
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdio.h>
#include <stdlib.h>
void _prompt();
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
int _strlen(char *s);
int _putchar(char c);
int _putstr(char *s);
char *_concat(char *src, char *dest);
char **parseintab(char *str);
int child_process(char **argv);
#endif
