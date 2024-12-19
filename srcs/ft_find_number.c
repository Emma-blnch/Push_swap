#include "../includes/ft_push_swap.h"

int	find_minimum(t_stack *stack)
{
	int			min;
	t_node		*current;

	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	find_min_position(t_stack *stack, int min)
{
	int			position;
	t_node		*current;

	current = stack->top;
	position = 0;
	while (current)
	{
		if (current->value == min)
			break ;
		current = current->next;
		position++;
	}
	return (position);
}