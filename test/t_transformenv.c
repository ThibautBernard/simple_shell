#include "../holberton.h"

int main()
{
	envNodes *envt;

	envt = transformEnv();
	free_list(envt);
}
