#include "monty.h"
/**
 * free_list - frees a dlistint_t list.
 * @head: head of the list
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
/**
 * nofile - prints error
 * @filename: file passed
 */
void nofile(const char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
/**
 * free_data - frees data struct
 */
void free_data(void)
{
	free_list(data.stack);
	free(data.string);
	fclose(data.file);
	exit(EXIT_FAILURE);
}
/**
 * nop - does nothing.
 * @stack: the node added to the stack.
 * @line_number: the line number.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
