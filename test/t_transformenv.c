#include "../holberton.h"
size_t print_list(envNodes *h)
{
	int i = 0;

	while (h != NULL)
	{
		if (h->str != NULL)
			printf("[%i] %s\n",i, h->str);
		else
			printf("[0] (nil)\n");

		h = h->next;
		i++;
	}
	return (i);
}

int main()
{
	envNodes *envt;
	
	envt = transformEnv();
	print_list(envt);
	printf("***************FREE************");
	free_list(envt);
	printf("**************FREE*************");

	return(0);
}
