/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:57:25 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/17 14:47:30 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	*get_stack_values(t_stack *stack)
{
	int		*values;
	int		i;
	t_node	*current;

	values = malloc(sizeof(int) * stack->size);
	if (!values)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		values[i] = current->value;
		current = current->next;
		i++;
	}
	return (values);
}

void	update_stack_values(t_stack *stack, int *values)
{
	int		i;
	t_node	*current;

	current = stack->top;
	while (current)
	{
		i = 0;
		while (i < stack->size)
		{
			if (current->value == values[i])
			{
				current->value = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

// int	find_closest_bit(t_stack *stack, int bit)
// {
// 	int		position;
// 	int		i;
// 	t_node	*current;

// 	current = stack->top;
// 	position = -1;
// 	i = 0;
// 	while (current)
// 	{
// 		if (((current->value >> bit) & 1) == 0)
// 		{
// 			position = i;
// 			break ;
// 		}
// 		current = current->next;
// 		i++;
// 	}
// 	return (position);
// }
