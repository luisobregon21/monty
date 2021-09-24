#include "monty.h"
/**
 * main - reads monty file and runs opcodes
 * @ac: arguement count
 * @av: elements
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	FILE *file;
	char *content;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: monty file");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if(!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE)
	}

	return (0);
}
/**
 * file_open - traverse each line of file and execute the monty code
 * @file: 
 */
void file_open(const char *filename)
{
}
