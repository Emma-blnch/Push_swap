/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:15:24 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/13 16:40:49 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_a || !stack_b || stack_b->size == 0)
		return ;
	temp = stack_b->top;
	push(stack_a, temp->value);
	stack_b->top = temp->next;
	stack_b->size--;
	free(temp);
	ft_printf("pa\n");
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*temp;

	if (!stack_a || !stack_b || stack_a->size == 0)
		return ;
	temp = stack_a->top;
	push(stack_b, temp->value);
	stack_a->top = temp->next;
	stack_a->size--;
	free(temp);
	ft_printf("pb\n");
}
