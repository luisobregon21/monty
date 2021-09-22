#include "test.h"
/**
 * This function just plays around with doubly linked list
 * in an interactive mode.
 */

int main()
{
	dlistint_t *head;

	head = malloc(sizeof(dlistint_t));
	if (head == NULL)
		return (-1);
	else
	{
		head->next = NULL;
		head->prev = NULL;
		printf("Give a value to the node: \n");
		scanf("%d", &head->n);
	}
	printf("This is the value of your node:%d \n", head->n);
	return (0);
}
