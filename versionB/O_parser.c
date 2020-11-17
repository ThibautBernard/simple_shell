#include "O_holberton.h"

/*work at begin of a words*/

int _strlendelim(char *str, char *d)
{
	int i;

	for (i = 0; str[i] && str[i] != d[0] ; i++)
		;
	return (i);
}

char *O_concat(char *s1, char *s2)
{
	char *ret;
	int i;
	int j;

	ret = malloc(sizeof(char)*(_strlen(s1) + _strlen(s2) + 1 ));
	if (ret == NULL)
		return (0);
	for(i = 0; s1[i]; i++)
		ret[i] = s1[i];
	for (j = 0; s2[j]; j++)
	{
		ret[i] = s2[j];
		i++;
	}
	ret[i] = '\0';

	return (ret);
}
char **O_parseintab(char *str, char *d)
{
	char **tb;
	int i;
	int j;
	int k;

	tb = malloc(sizeof(char *) * (getnbwords(str, d) + 1));
	if (tb == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == d[0])
			i++;
		if (_ischar(str[i]) == 1)
		{
			tb[k] = malloc(sizeof(char) * (_strlendelim(&str[i], d) + 1));
			if (tb[k] == NULL)
				return (NULL);
		}
		j = 0;
		while (str[i] != d[0] && str[i] != '\0')
		{
			tb[k][j] = str[i];
			j++;
			i++;
		}
		tb[k][j] = '\0';
		k++;
	}
	tb[k] = NULL;

	return (tb);
}

void freetab(char **tb)
{
	int j;

	for (j = 0; tb[j]; j++)
		free(tb[j]);
	free(tb);
}

int intcheckinpath(char *stcmd)
{
	struct stat *st;
	int i;
	int b, k;
	char **tb;
	char *tmp;
	char *s1;

	if (stcmd == NULL)
		return (-1);
	tb = O_getenv("PATH");
	i = 0;
	b = 0;
	st = malloc(sizeof(struct stat));
	if (st == NULL)
		return (-1);
	while(tb[i])
	{
		s1 = O_concat(tb[i],"/");
		tmp = O_concat(s1, stcmd);
		k = stat(tmp, st);
		if (k  == 0)
			b = 1;
		free(s1);
		free(tmp);
		i++;
	}
	free(st);
	freetab(tb);

	return (b);
}
char *_checkinpath(char *stcmd)
{
	struct stat *st;
	int i;
	int b, k, l;
	char **tb;
	char *tmp;
	char *s1;
	char *res;

	if (stcmd == NULL)
		return (NULL);
	tb = O_getenv("PATH");
	i = 0;
	b = 0;
	st = malloc(sizeof(struct stat));
	if (st == NULL)
		return (NULL);
	while(tb[i])
	{
		s1 = O_concat(tb[i],"/");
		tmp = O_concat(s1, stcmd);
		k = stat(tmp, st);
		//printf("%s\n", tmp);
		if (k  == 0)
		{
			res = malloc(sizeof(char) * (_strlen(tmp)+ 1));
			for (l = 0; tmp[l]; l++)
				res[l] = tmp[l];
			res[l] = '\0';
			b = 1;
		}
		free(s1);
		free(tmp);
		i++;
	}
	free(st);
	freetab(tb);

	if (b == 0)
	{
		return (NULL);
	}
	else
		return (res);
}
/*typedef struct bui 
{
        char *name;
	int (*f)(void);
		} bui;
int _exit1(void)
{
	printf("exit\n");
	return (0);
}
int checkinbuiltin()
{
	bui b1[] = {
		{"exit", _exit1},
		{NULL, NULL}
	};
	b1[0].f();
	return (0);

}*/
char **O_getenv(char *envname)
{
	char *tb;
	char **tmp;
	int i;
	int j;
	int b;
	int tblen;

	for (i = 0; environ[i]; i++)
	{
		tmp = O_parseintab(environ[i], "=");
		b = 1;
		for (j = 0; tmp[0][j]; j++)
		{
			if (envname[j] != tmp[0][j])
				b = 0;
		}
		if (b == 1)
		{
			tblen = _strlen(tmp[1]);
			tb = malloc(sizeof(char) * tblen + 1);
			if (tb == NULL)
				return (NULL);
			for (j = 0; tmp[1][j]; j++)
				tb[j] = tmp[1][j];
			tb[j] = '\0';
		}
		freetab(tmp);
	}
	tmp = O_parseintab(tb, ":");
	free(tb);
	return (tmp);
}
/*int main()
{
	checkinbuiltin();
	return (0);
}*/
/*Testcheckinpath*/
/*int main()
  {
  printf("%i\n", checkinpath(""));

  }*/
/*Test 0_getEnv*/
/*int main()
  {
  char **tb1;
  int i;	

  tb1 = O_getenv("OLDPWD");
  for (i = 0; tb1[i]; i++)
  printf("GetPATH : %s\n", tb1[i]);
  freetab(tb1);
  return (0);
  }*/
/*
*test parseintab*/

/*   int main()
   {
  char *s = "XDG_SESSION_ID=7n";
   char *s1 = "toto";
   char *s2 = "avion:b";
   char *s3 = "::::::avion:::::bateau";
  char *s4 = "::::avion::::::bateau::::";
   char *d = ":";
   char **tb;
   int j;
   printf("Expected 5 : %i\n", _strlendelim(s, d));
   printf("Expected 4 : %i\n", _strlendelim(s1, d));
   printf("Expected 3 : %i\n", _strlendelim(&s2[6] , d));
  printf("Expected 0 : %i\n", _strlendelim(s3, d));
   printf("Expected 0 : %i\n", _strlendelim(s4, d));

   tb = O_parseintab(s2, d);
   for (j = 0; tb[j]; j++)
   {
   printf("%i\n", j);
   printf("%s\n", tb[j]);
   }
   for (j = 0; tb[j]; j++)
   {
   printf("free : %i\n", j);
   free(tb[j]);
   }
   free(tb);
   return (0);
   }*/

