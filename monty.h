#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* DATA STRUCTURES down below*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct leave - file, char*, stack_t
 * @file: file used
 * @string: line of file
 * @stack: the node
 */
typedef struct leave
{
FILE *file;
char *string;
stack_t *stack;
int line;
}
leave_t;
extern leave_t data;

/* PROTOTYPES DOWN BELOW */
void file_open(const char *filename);
void push_perror(int line);
int number_test(char *hold, char *buf, int line);
void (*opcode_conv(char *func_name)) (stack_t **stack, unsigned int line);
void free_list(stack_t *head);
void nofile(const char *filename);
void free_data(void);

/* PROTOTYPES FOR OPCODES BELOW*/
stack_t *push(stack_t **stack, int value);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

#endif /*_GNU_SOURCE_*/
