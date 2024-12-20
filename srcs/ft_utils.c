/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:32:33 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/20 11:00:06 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
	free(stack);
}

void	error_exit(t_stack *stack)
{
	ft_printf("Error\n");
	free_stack(stack);
	exit(EXIT_FAILURE);
}

// atoi
static int	check_overflow(long result, int sign, char next_digit)
{
	long	test;

	test = result * 10 + (next_digit - '0');
	if (sign == 1 && test > INT_MAX)
		return (1);
	if (sign == -1 && test < INT_MIN)
		return (1);
	return (0);
}

int	ft_atoi_safe(const char *str, int *is_valid)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		if (check_overflow(result, sign, *str))
		{
			*is_valid = 1;
			return (0);
		}
		result = result * 10 + (*str++ - '0');
	}
	if (*str != '\0')
		return (*is_valid = 1, 0);
	return ((int)result * sign);
}
