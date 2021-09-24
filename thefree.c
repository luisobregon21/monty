#include "monty.h"
/**
 * free_list - frees a dlistint_t list.
 * @stack: head of the list
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
