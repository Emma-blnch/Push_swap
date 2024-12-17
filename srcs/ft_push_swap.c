/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:36:46 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/17 14:19:42 by eblancha         ###   ########.fr       */
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
	else if (stack_a->size > 5)
	{
		normalize_stack(stack_a);
		radix_sort(stack_a, stack_b);
	}
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
		error_exit(stack_a);
	stack_b = init_stack();
	if (!stack_b)
		return (ft_printf("Error\n"), 1);
	choose_sort_algo(stack_a, stack_b);
	return (free_stack(stack_a), free_stack(stack_b), 0);
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

// void test_normalize_stack() {
//     t_stack *stack = init_stack();
//     push(stack, 4);
//     push(stack, 5);
//     push(stack, 3);
//     push(stack, 2);
//     push(stack, 1);
//     push(stack, 8);

// 	printf("Before normalization:\n");
// 	print_stack(stack);
//     normalize_stack(stack);
// 	printf("after normalization:\n");
//     print_stack(stack);
//     free_stack(stack);
// }

// void test_sort_bit() {
//     t_stack *stack_a = init_stack();
//     t_stack *stack_b = init_stack();
//     push(stack_a, 4);
//     push(stack_a, 5);
//     push(stack_a, 3);
//     push(stack_a, 2);
// 	push(stack_a, 1);
// 	push(stack_a, 8);

// 	printf("Before sort_bit:\n");
//     print_stack(stack_a);
//     sort_bit(stack_a, stack_b, 0); // Trie par le bit le moins significatif
//     printf("after sort_bit:\n");
// 	print_stack(stack_a); // Vérifiez l'ordre.
//     print_stack(stack_b); // Vérifiez l'ordre.
//     free_stack(stack_a);
//     free_stack(stack_b);
// }

// int main()
// {
// 	// test_normalize_stack();
// 	test_sort_bit();
// 	return (0);
// }


// commande shell : ARG=$(seq -50 50 | shuf -n 10 | tr '\n' ' ')
// echo "$ARG" | xargs ./push_swap | ./checker_linux $ARG
