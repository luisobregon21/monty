#include "monty.h"
leave_t data = {NULL, NULL, NULL};
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
	char *cut = " \n*~$%)(\t\r&", *key = NULL;
	size_t str_len = 0;
	int value = 0, count = 1;

	data.file = fopen(filename, "r");
	if (!data.file)
		nofile(filename);
	while (getline(&data.string, &str_len, data.file) != EOF)
	{
		key = strtok(data.string, cut);
		if (key == NULL)
		{
			count++;
			continue;
		}
		if (key[0] != '#')
		{
			if (strncmp(key, "push", 4) == 0)
			{
				printf("what is the key?:[%s]", key);
				key = strtok(NULL, cut);
				if (number_test(key, count) == 0)
				{
					value = atoi(key);
					push(&data.stack, value);
				}
			}
			else
			{
				if (!data.string)
				{
					fprintf(stderr, "L%d: unknown instruction %s\n", count, data.string);
					free_data();
				}
				opcode_conv(data.string)(&data.stack, count);
			}
		}
		count++;
	}
	free_data();
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
 * @buf: the elements that follow "push"
 * @line: the line we are at
 * Return: 0 if what follows push is a digit or 1 if not.
 */
int number_test(char *buf, int line)
{
	int idx;

	if (buf == NULL)
	{
		fclose(data.file);
		push_perror(line, data.string);
	}
	for (idx = 0; buf[idx] != '\0'; idx++)
	{
		if (buf[idx] == '-')
		{
			if (isdigit(buf[idx + 1]) != 0)
			{
				continue;
			}
			else
			{
				fclose(data.file);
				push_perror(line, data.string);
				return (1);
			}
		}
		else if (isdigit(buf[idx]) != 0)
		{
			continue;
		}
		else
		{
			fclose(data.file);
			push_perror(line, data.string);
			return (1);
		}
	}
	return (0);
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
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
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