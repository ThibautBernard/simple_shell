#include "O_holberton.h"
/*int main(int ac, int **av)
{
	pid_t child_pid;
	int status;
	char *input;
	char **tb;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_pid == 0)
	{
		//DisplayPrompt
		//GetInput
		tb = parseintab(input, " ");
		launchfunction(tb);
		freetab(tb);
	}
	else
	{
		wait(&status);
		printf("Oh, it's all better now\n");
	}
	return (0);
}
*/
int launchfunction(char **tb)
{
	char *s;

	s = _checkinpath(tb[0]);
	if (s != NULL)
	{
		//if (execve(s, tb, NULL) == -1)
			printf("ERROR\n");
		free(s);
		return (1);
	}
	else
		return (0);
}

int main()
{
	char *tb1[] = {"ls", "-l", NULL};
	char s1[] = "bateau";
	char s2[] = "avion";
	char *s3 = "::::::avion:::::bateau";
	char *s;
	char **tb;
	int i;
	tb = O_parseintab(s3, ":");
	for (i = 0; tb[i]; i++)
	{
		printf("%s\n", tb[i]);
	}
	freetab(tb);
	s = _checkinpath("ls");
	if (s != NULL)
	{
		printf("%s\n", s);
		free(s);
	}
	launchfunction(tb1);
	return (0);
}
