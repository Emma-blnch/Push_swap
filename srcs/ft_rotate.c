/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:15:47 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/12 10:06:09 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*last;
	t_node	*temp;

	if (!stack_a || stack_a->size < 2)
		return ;
	temp = stack_a->top;
	last = stack_a->top;
	while (last->next)
		last = last->next;
	stack_a->top = temp->next;
	last->next = temp;
	temp->next = NULL;
}

void	rb(t_stack *stack_b)
{
	t_node	*last;
	t_node	*temp;

	if (!stack_b || stack_b->size < 2)
		return ;
	temp = stack_b->top;
	last = stack_b->top;
	while (last->next)
		last = last->next;
	stack_b->top = temp->next;
	last->next = temp;
	temp->next = NULL;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
