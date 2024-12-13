/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:08:11 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/13 10:11:18 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	sort_two_numbers(t_stack *stack_a)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	if (stack_a->top->value > stack_a->top->next->value)
		sa(stack_a);
}

// Sort 3 numbers
int	get_case_id(t_stack *stack_a)
{
	int	top;
	int	mid;
	int	last;

	top = stack_a->top->value;
	mid = stack_a->top->next->value;
	last = stack_a->top->next->next->value;
	if (top > mid && mid > last)
		return (1);
	if (top < mid && mid > last)
		return (2);
	if (top > mid && mid < last)
		return (3);
	if (top < mid && mid < last)
		return (0);
	return (-1);
}

void	sort_three_numbers(t_stack *stack_a)
{
	int	case_id;

	if (!stack_a || stack_a->size < 3)
		return ;
	case_id = get_case_id(stack_a);
	if (case_id == 1)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (case_id == 2)
	{
		rra(stack_a);
		if (stack_a->top->value > stack_a->top->next->value)
			sa(stack_a);
	}
	else if (case_id == 3)
	{
		if (stack_a->top->value > stack_a->top->next->next->value)
			ra(stack_a);
		else
			sa(stack_a);
	}
}
