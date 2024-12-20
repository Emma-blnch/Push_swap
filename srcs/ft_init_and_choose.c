/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_and_choose.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:36:46 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/20 11:28:21 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (!stack->top)
		stack->top = new_node;
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
}

int	validate_input(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		value;
	int		is_valid;

	i = 1;
	while (i < argc)
	{
		is_valid = 0;
		value = ft_atoi_safe(argv[i], &is_valid);
		if (is_valid)
			return (0);
		push(stack, value);
		i++;
	}
	if (!is_valid_stack(stack))
		return (0);
	return (1);
}

int	is_valid_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*checker;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (0);
			checker = checker->next;
		}
		current = current->next;
	}
	return (1);
}

void	choose_sort_algo(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_two_numbers(stack_a);
	else if (stack_a->size == 3)
		sort_three_numbers(stack_a);
	else if (stack_a->size == 4)
		sort_four_numbers(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five_numbers(stack_a, stack_b);
	else if (stack_a->size > 5 && stack_a->size <= 100)
		chunk_sort(stack_a, stack_b);
	else if (stack_a->size > 100)
	{
		normalize_stack(stack_a);
		radix_sort(stack_a, stack_b);
	}
}

// void	print_stack(t_stack *stack)
// {
// 	t_node	*current;

// 	current = stack->top;
// 	ft_printf("Stack (size: %d):\n", stack->size);
// 	while (current)
// 	{
// 		ft_printf("%d\n", current->value);
// 		current = current->next;
// 	}
// }
