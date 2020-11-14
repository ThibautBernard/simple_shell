#include "../holberton.h"

int main()
{
	char *s = "avion:toto:bateau";
	char *d	= ":";

	char *s1 = "avion:bateau";
	char *s2 = "avion";
	char *s3 = "::::::::::::::::avion::::::::::::";
	char *s4 = ":::::::::::::::avion";
	char *s5 = "avion::::::::::::";
	char *s6 = "avion:bateau:::::::::::";
	char *s7 = ":::::::::::::::avion:bateau";
	char *s8 = ":::::::::::::::avion:bateau:::::::::::::::";
	char *s9 = ":::::::::::::::avion::::::bateau:::::::::::::::";
	printf("[getnbwords] expected: 3 return : %i\n", getnbwords(s, d));
	printf("[getnbwords] expected: 2 return : %i\n", getnbwords(s1, d));
	printf("[getnbwords] expected: 1 return : %i\n", getnbwords(s2, d));
	printf("[getnbwords] expected: 1 return : %i\n", getnbwords(s3, d));
	printf("[getnbwords] expected: 1 return : %i\n", getnbwords(s4, d));
	printf("[getnbwords] expected: 1 return : %i\n", getnbwords(s5, d));
	printf("[getnbwords] expected: 2 return : %i\n", getnbwords(s6, d));
	printf("[getnbwords] expected: 2 return : %i\n", getnbwords(s7, d));
	printf("[getnbwords] expected: 2 return : %i\n", getnbwords(s8, d));
	printf("[getnbwords] expected: 2 return : %i\n", getnbwords(s9, d));
	return (0);
}
