/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:36:46 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/11 17:01:45 by eblancha         ###   ########.fr       */
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

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
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

	if (argc < 2)
		return (ft_printf("Error\n"), 1);
	stack_a = init_stack();
	if (!stack_a)
		return (ft_printf("Error\n"), 1);
	if (!validate_input(argc, argv, stack_a))
		return (free_stack(stack_a), 1);
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}
