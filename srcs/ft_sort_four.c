/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:19:46 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/19 13:35:50 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

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
