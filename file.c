#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void pall(char *string);
int main(int argc, char **argv)
	//posible edge cases si no existe el file oh si el file no tiene nada
{
	FILE *file;
	char string[1000];
	int lidx;
	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(string, sizeof(string), file))
	{
		lidx = (strlen(string) -1);
		string[lidx] = '\0';
		pall(string);
	}
	return (0);
}

void pall(char *string)
{
	printf("%s\n", string);
}
