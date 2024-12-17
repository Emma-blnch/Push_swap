/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:16:39 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/17 13:30:24 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	find_max_bits(t_stack *stack)
{
	int		max;
	int		bits;
	t_node	*current;

	max = 0;
	bits = 0;
	current = stack->top;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
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
	int		i;
	int		*values;
	t_node	*current;

	i = 0;
	if (!stack || stack->size == 0)
		return ;
	values = malloc(sizeof(int) * stack->size);
	if (!values)
		return ;
	current = stack->top;
	while (current)
	{
		values[i++] = current->value;
		current = current->next;
	}
	sort_array(values, stack->size);
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
	free(values);
}

void	sort_bit(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int	size;
	int	i;

	i = 0;
	size = stack_a->size;
	while (i < size)
	{
		if (((stack_a->top->value >> bit) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_b, stack_a);
		i++;
	}
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	bit;

	bit = 0;
	max_bits = find_max_bits(stack_a);
	while (bit < max_bits)
	{
		sort_bit(stack_a, stack_b, bit);
		bit++;
	}
}
