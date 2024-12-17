/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:09:16 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/17 14:35:21 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	sort_five_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	i;
	int	position;

	if (!stack_a || !stack_b || stack_a->size < 5 || is_sorted(stack_a))
		return ;
	i = 0;
	while (i < 2)
	{
		min = find_minimum(stack_a);
		position = find_min_position(stack_a, min);
		while (stack_a->top->value != min)
		{
			if (position <= stack_a->size / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_b, stack_a);
		i++;
	}
	sort_three_numbers(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
