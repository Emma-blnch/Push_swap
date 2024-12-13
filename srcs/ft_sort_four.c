/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:19:46 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/13 14:21:17 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_four_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	position;

	if (!stack_a || !stack_b || stack_a->size < 4)
		return ;
	if (is_sorted(stack_a))
		return ;
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
	sort_three_numbers(stack_a);
	pa(stack_a, stack_b);
}
