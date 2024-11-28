#include <stdio.h>

typedef struct s_stack
{
    int             nb;
    int             index;
    struct s_stack  *target;
    struct s_stack  *next;
}   t_stack;

void print_stack(char stack_name, t_stack *stack)
{
	printf("STACK %c:\n", stack_name);
	while (stack)
	{
		printf("{index: %d, nb: %d", stack->index, stack->nb);
		if (stack->target)
			printf(", target: %d", stack->target->nb);
		if (stack->next)
			printf(", next: %d", stack->next->nb);
		printf("}\n");
		stack = stack->next;
	}
	printf("\n");
}

int main(void)
{
	t_stack node2 = {2, 2, NULL, NULL};
	t_stack node1 = {1, 1, NULL, &node2};
	t_stack	node0 = {0, 0, NULL, &node1};
	t_stack *a = &node0;
	print_stack('A', a);

	t_stack node5 = {5, 2, NULL, NULL};
	t_stack node4 = {4, 1, NULL, &node5};
	t_stack	node3 = {3, 0, NULL, &node4};
	t_stack *b = &node3;
	print_stack('B', b);

	printf("---\n\n");

	(&node1)->target = &node4;
	print_stack('A', a);

	printf("---\n\n");

	(&node1)->target = NULL;
	print_stack('A', a);
	print_stack('B', b);
	
	return (0);
}
