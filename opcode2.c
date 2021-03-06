#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack: the node added to the stack.
 * @line_number: the line number.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node2, *head;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_data();
	}

	head = *stack;
	node2 = head->next;
	if (node2->next == NULL)
	{
		node2->prev = NULL;
		node2->next = head;
		head->next = NULL;
		head->prev = node2;
		*stack = node2;
	}
	else
	{
		node2->next->prev = head;
		head->next = node2->next;
		head->prev = node2;
		node2->next = head;
		node2->prev = NULL;
		*stack = node2;
	}
}

/**
 * add - adds the top two elements of the stack.
 * @stack: the node added to the stack.
 * @line_number: the line number.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_data();
	}
	else
	{
		tmp = *stack;
		*stack = tmp->next;
		(*stack)->n += tmp->n;
		(*stack)->prev = tmp->prev;
		free(tmp);
	}
}
/**
 * sub - subtracts the top two elements of the stack.
 * @stack: the node added to the stack.
 * @line_number: the line number.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_data();
	}
	else
	{
		tmp = *stack;
		*stack = tmp->next;
		(*stack)->n = tmp->n - (*stack)->n;
		(*stack)->prev = tmp->prev;
		free(tmp);
	}
}
/**
 * divide - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: the node added to the stack.
 * @line_number: the line number.
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_data();
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_data();
	}
	else
	{
		tmp = *stack;
		*stack = tmp->next;
		(*stack)->n = tmp->n / (*stack)->n;
		(*stack)->prev = tmp->prev;
		free(tmp);
	}
}

/**
 * mul - multiplies the second top element of the stack
 * by the top element of the stack.
 * @stack: the node added to the stack.
 * @line_number: the line number.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_data();
	}
	else
	{
		tmp = *stack;
		*stack = tmp->next;
		(*stack)->n = tmp->n * (*stack)->n;
		(*stack)->prev = tmp->prev;
		free(tmp);
	}
}
