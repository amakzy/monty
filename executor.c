#include "monty.h"

/**
 * get_opcodes - Retrieves an array of supported instructions
 *
 * Return: An array of instructions supported by this program
 */
instruction_t *get_opcodes(void)
{
	static instruction_t handlers[] = {
		{"push", mty_op_push},
		{"pall", mty_op_pall},
		{"pint", mty_op_pint},
		{"pop", mty_op_pop},
		{"swap", mty_op_swap},
		{"add", mty_op_add},
		{"nop", mty_op_nop},
		{"sub", mty_op_sub},
		{"div", mty_op_div},
		{"mul", mty_op_mul},
		{NULL, 0},
	};
	return (opcodes);
}

/**
 * execute_line - Executes a line of code
 * @line: The line to execute
 * @line_num: The line number of the line being executed
 * @stack_values: The stack of values of the program
 */
void run_line(char *line, int line_num, stack_t **stack)
{
	instruction_t *opcodes = get_opcodes();
	int i = 0;
	char *op = read_word(line, &i);

if(op) {
    if(op[0] != '#') {
      for(int j = 0; opcodes[j].name; j++) {
        if(equals(op, opcodes[j].name)) {
          opcodes[j].fn(stack, line_num);
          return;
        }
      } 

      print_error(line_num, op);
      exit_failure();
    }

    free(op);
  }
