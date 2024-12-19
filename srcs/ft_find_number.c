/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:59:48 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/19 15:06:15 by eblancha         ###   ########.fr       */
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

int	find_maximum(t_stack *stack)
{
	int		max;
	t_node	*current;

	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
		}
		current = current->next;
	}
	return (max);
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
