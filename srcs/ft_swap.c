/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:15:53 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/12 09:34:32 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*temp;

	if (!stack_a || stack_a->size < 2)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	temp->next = stack_a->top->next;
	stack_a->top->next = temp;
}

void	sb(t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_b || stack_b->size < 2)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	temp->next = stack_b->top->next;
	stack_b->top->next = temp;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
