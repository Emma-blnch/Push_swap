#include "../includes/ft_push_swap.h"

// void	move_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int min, int max)
// {
// 	int		size;
// 	int		count;
// 	int		pos;
// 	t_node	*current;

// 	count = 0;
// 	size = stack_a->size;
// 	current = stack_a->top;
// 	while (count < max - min)
// 	{
// 		pos = 0;
// 		while (current)
// 		{
// 			if (current->value >= min && current->value < max)
// 				break ;
// 			current = current->next;
// 			pos++;
// 		}
// 		if (!current)
// 			break ;
// 		smart_rotate(stack_a, pos);
// 		pb(stack_b, stack_a);
// 		count++;
// 		current = stack_a->top;
// 		if (stack_b->size > 1
// 			&& stack_b->top->value < stack_b->top->next->value)
// 			sa(stack_b);
// 	}
// }

void	move_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	int i;
	int size;

	i = 0;
    size = stack_a->size;
	 printf("Moving chunk to B: min = %d, max = %d\n", min, max);
	while (i < size)
	{
		if (stack_a->top->value >= min && stack_a->top->value < max)
		{
			 printf("Pushing %d from A to B\n", stack_a->top->value);
			pb(stack_b, stack_a);
		}
		else
		{
			printf("Rotating A: %d\n", stack_a->top->value);
			ra(stack_a);
		}
		i++;
	}
	printf("Chunk moved to B. Stack A:\n");
    print_stack(stack_a);
    printf("Stack B:\n");
    print_stack(stack_b);
}

int	find_insert_position(t_stack *stack_a, int value)
{
	int		pos;
	t_node	*current;

	if (!stack_a->top)
		return (0);
	current = stack_a->top;
	pos = 0;
	while (current)
	{
		if (current->value > value)
			break ;
		pos++;
		current = current->next;
	}
	return (pos);
}

void	move_chunk_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	while (stack_b->size > 0)
	{
		if (!stack_b->top)
			break ;
		printf("Stack B before moving back to A:\n");
        	print_stack(stack_b);
		pos = find_insert_position(stack_a, stack_b->top->value);
		printf("Insert position in A for %d is %d\n", stack_b->top->value, pos);
		smart_rotate(stack_a, pos);
		pa(stack_a, stack_b);
		printf("Moved %d from B to A\n", stack_b->top->value);
	}
	printf("All chunks moved back to A. Stack A:\n");
   	print_stack(stack_a);
}

void	smart_rotate(t_stack *stack, int pos)
{
	if (!stack->top)
		return ;
	if (pos <= stack->size / 2)
	{
		while (pos-- > 0)
			ra(stack);
	}
	else
	{
		while (pos++ < stack->size)
			rra(stack);
	}
}

void    chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
    int	min;
    int	max;
    int i;
    int chunk_size;
    int chunk_count;

    if (stack_a->size <= 5 || is_sorted(stack_a))
        return ;
    normalize_stack(stack_a);
    if (stack_a->size < 10)
        chunk_count = 1;
    else
        chunk_count = stack_a->size / 10;
    chunk_size = stack_a->size / chunk_count;
    i = 0;
	 printf("Starting chunk sort with %d chunks\n", chunk_count);
    while (i < chunk_count)
    {
        min = i * chunk_size;
        if (i == chunk_count - 1)
            max = INT_MAX;
        else
            max = (i + 1) * chunk_size;
	printf("Processing chunk %d: min = %d, max = %d\n", i, min, max);
        move_chunk_to_b(stack_a, stack_b, min, max);
        i++;
    }
    move_chunk_back_to_a(stack_a, stack_b);
	printf("Chunk sort completed. Final stack A:\n");
}
