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
	while (i < size)
	{
		if (stack_a->top->value >= min && stack_a->top->value < max)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
		i++;
	}
}

int	find_insert_position(t_stack *stack_a, int value)
{
	int		pos;
	t_node	*current;

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
		pos = find_insert_position(stack_a, stack_b->top->value);
		smart_rotate(stack_a, pos);
		pa(stack_a, stack_b);
	}
}

void	smart_rotate(t_stack *stack, int pos)
{
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
    while (i < chunk_count)
    {
        min = i * chunk_size;
        if (i == chunk_count - 1)
            max = INT_MAX;
        else
            max = (i + 1) * chunk_size;
        move_chunk_to_b(stack_a, stack_b, min, max);
        i++;
    }
    move_chunk_back_to_a(stack_a, stack_b);
}
