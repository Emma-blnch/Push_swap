/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:15:24 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/17 13:04:01 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	push_stack(t_stack *stack, int value)
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

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_a || !stack_b || stack_b->size == 0)
		return ;
	temp = stack_b->top;
	push_stack(stack_a, temp->value);
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
	push_stack(stack_b, temp->value);
	stack_a->top = temp->next;
	stack_a->size--;
	free(temp);
	ft_printf("pb\n");
}
