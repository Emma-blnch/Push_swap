/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:57:25 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/17 14:00:33 by eblancha         ###   ########.fr       */
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
