/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:58:38 by eblancha          #+#    #+#             */
/*   Updated: 2025/01/06 13:32:04 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	stack_a = init_stack();
	if (!stack_a)
		error_exit(stack_a);
	if (!validate_input(argc, argv, stack_a))
		error_exit(stack_a);
	stack_b = init_stack();
	if (!stack_b)
		error_exit(stack_b);
	choose_sort_algo(stack_a, stack_b);
	return (free_stack(stack_a), free_stack(stack_b), 0);
}

// commande shell : ARG=$(seq -50 50 | shuf -n 10 | tr '\n' ' ')
// echo "$ARG" | xargs ./push_swap | ./checker_linux $ARG