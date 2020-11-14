#include "../holberton.h"
int main()
{
	char *s = "avion";
	char *s1 = "bateau";
	char *s3;

	printf("[_strlen] expected : 5, return : %i\n", _strlen(s));
	s3 = _concat(s, s1);
	printf("[_concat] expected : avionbateau, return : %s\n", s3);
	free(s3);
	return (0);
}
