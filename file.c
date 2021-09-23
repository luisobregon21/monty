#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int number_test(char *string);
int main(int argc, char **argv)
	//posible edge cases si no existe el file oh si el file no tiene nada
{
	FILE *file;
	char *string = NULL;
	size_t str_len = 0;
	int count = 1;
	char *key = NULL;
	char *cut = "\n\r\t /$%&~*";
	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&string, &str_len, file) != EOF)
	{/** guardas el return de strtok en el string key **/
		key = strtok(string, cut);
		if (strcmp(key, "push") == 0)
		{
			printf("push\n");
			printf("line: %d\n", count);
			key = strtok(NULL, cut);
			if (key == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", count);
			}
			if (number_test(key) == 0)
			{
				/* aqui llamamos al function pointer de push con atoi(key) de parametro*/
				printf("number:%d\n", atoi(key));
			}
			else if (number_test(key) == 1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", count);
				exit (EXIT_FAILURE);
			}
			/*posible edge case, creo que deberia seguir tokenizando hasta que el token sea NULL
			 * y solo imprimir un error si me eh quedado sin token en los que buscar un numero */
		}
		/* hay que cambiar este else if para que use los function pointers*/
		if (strcmp(key, "pall") == 0)
		{
			/* aqui hay que usar los function pointers*/
			printf("pall\n");
		}
		count++;
	}
	return (0);
}

int number_test(char *string)
{
	int idx;

	for (idx = 0; string[idx] != '\0'; idx++)
	{
		if (isdigit(string[idx]) != 0)
		{
			return (0);
		}
	}
	return (1);
}
