#include "../holberton.h"
int main()
{
	char *s = "PATH=/";
	char *c;
	envNodes *envt;

	envt = transformEnv();
	c = _getenv(s, &envt);
	printf("->%s\n", c);
	free_list(envt);
	return (0);
}
/*
envNodes *envt;
char *argv = "ls";

envi = transformEnv();
path = checkPath(argv, &envt);


return (0);*/
