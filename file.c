#include "monty.h"
int global = 0;
/**
 * main - reads monty file and runs opcodes
 * @argc: arguement counter
 * @argv: arguements pass, in our case the executable and name.
 * Return: 0 if program ran smoothly.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file_open(argv[1]);
	return (0);
}
/**
 * file_open - traverse each line of a file and executes monty opcode
 * @filename: the file being passed
 */
void file_open(const char *filename)
{
	char *cut = " \n*~$%)(\t\r&", *key = NULL, *string = NULL;
	size_t str_len = 0;
	unsigned int value = 0, count = 1;
	FILE *file = fopen(filename, "r");
	stack_t *stack = NULL;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&string, &str_len, file) != EOF)
	{
		key = strtok(string, cut);
		if (strcmp(key, "push") == 0)
		{
			key = strtok(NULL, cut);
			if (key == NULL)
			{
				push_perror(count, string);
			}
			if (number_test(key) == 0)
			{
				value = atoi(key);
				opcode_conv("push")(&stack, value);
			}
			else if (number_test(key) == 1)
			{
				push_perror(count, string);
			}
		}
		else
		{
			opcode_conv(string)(&stack, count);
		}
		count++;
	}
	free_list(stack);
	free(string);
	fclose(file);
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

/**
 * *opcode_conv - calls the corresponding opcode function to their string
 * @func_name: the opcode name, example: "pall"
 * Return: the function that needs to be executed.
 */
void (*opcode_conv(char *func_name))(stack_t **stack, unsigned int line)
{
	int idx;

	instruction_t fp[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (idx = 0; fp[idx].opcode != NULL; idx++)
	{
		if (strcmp(fp[idx].opcode, func_name) == 0)
		{
			return (fp[idx].f);
		}
	}
	return (NULL);
}
