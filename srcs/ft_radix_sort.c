/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:16:39 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/17 14:47:25 by eblancha         ###   ########.fr       */
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
	int		*values;

	if (!stack || stack->size == 0)
		return ;
	values = get_stack_values(stack);
	sort_array(values, stack->size);
	update_stack_values(stack, values);
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
	// if (stack_b->size <= 5)
	// 	sort_five_numbers(stack_b, stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

// void	sort_bit(t_stack *stack_a, t_stack *stack_b, int bit)
// {
// 	int	size;
// 	int	position;

// 	size = stack_a->size;

// 	while (size--)
// 	{
// 		if (((stack_a->top->value >> bit) & 1) == 0)
// 			pb(stack_b, stack_a);
// 		else
// 		{
// 			position = find_closest_bit(stack_a, bit);
// 			if (position <= stack_a->size / 2)
// 				ra(stack_a);
// 			else
// 				rra(stack_a);
// 		}
// 	}
// 	while (stack_b->size > 0)
// 		pa(stack_a, stack_b);
// }

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	bit;

	bit = 0;
	max_bits = find_max_bits(stack_a);
	while (bit < max_bits)
	{
		sort_bit(stack_a, stack_b, bit);
		if (is_sorted(stack_a))
			break ;
		bit++;
	}
}
