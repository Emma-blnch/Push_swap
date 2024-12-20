/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:57:25 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/20 10:41:51 by eblancha         ###   ########.fr       */
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

void	sort_array(int *array, int size)
{
	int	i;
	int	swapped;
	int	temp;

	if (!array || size <= 1)
		return ;
	swapped = 1;
	while (swapped)
	{
		i = 0;
		swapped = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
			}
			i++;
		}
	}
}

void	normalize_stack(t_stack *stack)
{
	int		*values;

	if (!stack || stack->size == 0)
		return ;
	values = get_stack_values(stack);
	sort_array(values, stack->size);
	update_stack_values(stack, values);
	free(values);
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
