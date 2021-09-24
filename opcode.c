#include "monty.h"
/**
 * push - adds an element to the stack.
 * @stack: the node added to the stack.
 * @value: the value of the element.
 * Return: the node created
 */
stack_t *push(stack_t **stack, int value)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_data();
	}
	new->n = value;
	new->prev = NULL;
	if (*stack == NULL)
	{
		new->next = *stack;
		*stack = new;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	return (new);
}

/**
 * pall - prints all values on the stack, starting from top.
 * @stack: the stack being printed.
 * @line_number: the line number.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*stack == NULL)
	{
		return;
	}

	tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: the stack that is given
 * @line_number: the line number.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_data();
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: the stack that holds the elements.
 * @line_number: the line number.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_data();
	}

	tmp = *stack;

	if (tmp->next != NULL)
	{
		*stack = tmp->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
		free(tmp);
}
