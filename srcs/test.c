# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stak {
	t_node	*top;
	int		size;
}	t_stack;

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while(current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	printf("Stack (size: %d):\n", stack->size);
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}
// test push
int main(void)
{
    t_stack *stack = init_stack();
    if (!stack)
        return (printf("FAIL: Could not initialize stack\n"), 1);

    push(stack, 42);
    if (!stack->top || stack->top->value != 42 || stack->size != 1)
        printf("FAIL: push failed with single element\n");
    else
        printf("PASS: push single element\n");

    push(stack, 24);
    if (stack->top->value != 24 || stack->top->next->value != 42 || stack->size != 2)
        printf("FAIL: push failed with multiple elements\n");
    else
        printf("PASS: push multiple elements\n");
    print_stack(stack);
    free_stack(stack);
    return 0;
}

// test init stack
// int main(void)
// {
//     t_stack *stack = init_stack();
//     if (!stack)
//         printf("FAIL: init_stack returned NULL\n");
//     else if (stack->top || stack->size != 0)
//         printf("FAIL: init_stack did not initialize properly\n");
//     else
//         printf("PASS: init_stack\n");
//     free_stack(stack);
//     return 0;
// }
