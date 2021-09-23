#include "monty.h"
/**
 * main - reads monty file and runs opcodes
 * @argc: arguement counter
 * @argv: arguements pass, in our case the executable and name.
 * Return: 0 if program ran smoothly.
 */
int main(int argc, char **argv)
{
	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s filename\n", av[0]);
		exit(EXIT_FAILURE);
	}
	file_open(av[1]);
	return (0);
}
/**
 * file_open - traverse each line of a file and executes monty opcode
 * @filename: the file being passed
 */
void file_open(const char *filename)
{
	char cut = " \n*~$%)(\t\r&", *key == NULL, *string = NULL;
	size_t str_len = 0;
	int count = 1;
	FILE *file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&string, &str_len, file) != EOF)
	{
		/** guardas el return de strtok en el string key **/
		key = strtok(string, cut);
		if (strcmp(key, "push") == 0)
		{
			key = strtok(NULL, cut);
			if (key == NULL)
			{
				push_error(count, string);
			}
			if (number_test(key) == 0)
			{
				/* aqui llamamos al function pointer de push con atoi(key) de parametro*/
			}
			else if (number_test(key) == 1)
			{
				push_error(count, string);
			}
		}
		else
		{
			/* function pointers */
		}
		count++;
	}
}
/**
 * push_perror - prints an error message and exits
 * @line: the line number
 * @string: line to be free
 */
void push_perror(int line, char *string)
{
	fprintf(stderr, "L%d: usage: push integer\n", line);
	free(string);
	exit(EXIT_FAILURE);
}
/**
 * number_test - checks if what follows "push" is a number
 * @string: the elements that follow "push"
 * Return: 0 if what follows push is a digit or 1 if not.
 */
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
