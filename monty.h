#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define ALLOWED_INSTRUCTIONS 13
#define MAX_INSTRUCTION_PARTS 2

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
 * struct opcode_s - the opcode and its operand.
 * @opcode: the opcode.
 * @value: the value of the operand.
 *
 * Description: opcode and its value for easy parsing.
 */
typedef struct opcode_s
{
	char *opcode;
	int value;
} opcode_t;

/**
 * struct state_t - the current operand and queue mode.
 * @operand: the current value being passed to stack functions.
 * @queue_mode: the flag indicating if queue behaviour is needed.
 * 
 * Description: holds the single general state of the program.
*/
typedef struct state_s
{
	int operand;
	bool queue_mode;
} state_t;
extern state_t GLOBAL_ENV;


int read_file_and_execute(FILE *fd);
void parse_line(opcode_t *instruction, char *str, int line);

/* Stack */
void stack_push(stack_t **stack, int n);
int stack_pop(stack_t **stack);
void stack_print(stack_t **stack, bool fifo);
int stack_pint(stack_t **stack);
int stack_len(stack_t **stack);

/* Queue */
void queue_push(stack_t **queue, int n);
int queue_pop(stack_t **queue);
void queue_print(stack_t **queue);
int queue_pint(stack_t **queue);
int queue_len(stack_t **queue);

/* Operations */
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void multiply(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* Errors */
void malloc_error(void);
void malloc_check(void *ptr);
void unknown_instruction(int line, opcode_t *opcode);
void error_occured(char *msg, int line);

char *strtrim(const char *str);
bool is_whitespace(char ch);
void run_operation(stack_t **stack, opcode_t *operation, int line);

instruction_t *get_instructions();

#endif
