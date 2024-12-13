/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:36:46 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/13 13:59:49 by eblancha         ###   ########.fr       */
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
// push number first number in to bottom
// void	push(t_stack *stack, int value)
// {
// 	t_node	*new_node;

// 	new_node = malloc(sizeof(t_node));
// 	if (!new_node)
// 		return ;
// 	new_node->value = value;
// 	new_node->next = stack->top;
// 	stack->top = new_node;
// 	stack->size++;
// }

// push first number in top
void	push(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (!stack->top)
	{
		stack->top = new_node;
	}
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
}

// pour tests
void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	ft_printf("Stack (size: %d):\n", stack->size);
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}

int	validate_input(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		value;
	int		result;

	value = 0;
	i = 1;
	while (i < argc)
	{
		result = ft_atoi_safe(argv[i], &value);
		if (!result)
			return (ft_printf("Error\n"), 0);
		push(stack, result);
		i++;
	}
	if (!is_valid_stack(stack))
		return (ft_printf("Error\n"), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (ft_printf("Error\n"), 1);
	stack_a = init_stack();
	if (!stack_a)
		return (ft_printf("Error\n"), 1);
	if (!validate_input(argc, argv, stack_a))
		return (1);
	stack_b = init_stack();
	if (!stack_b)
		error_exit(stack_b);
	if (stack_a->size == 2)
		sort_two_numbers(stack_a);
	if (stack_a->size == 3)
		sort_three_numbers(stack_a);
	if (stack_a->size == 4)
		sort_four_numbers(stack_a, stack_b);
	if (stack_a->size == 5)
		sort_five_numbers(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
