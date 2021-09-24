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
