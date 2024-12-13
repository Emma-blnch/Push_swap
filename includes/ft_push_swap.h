/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:36:06 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/13 10:48:03 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node	*top;
	int		size;
}	t_stack;

// Main
int		main(int argc, char **argv);

// Initiliaze, check and free stack
int		is_valid_stack(t_stack *stack);
int		ft_atoi_safe(const char *str, int *is_valid);
int		validate_input(int argc, char **argv, t_stack *stack);
void	free_stack(t_stack *stack);
void	push(t_stack *stack, int value);
t_stack	*init_stack(void);

// Error messages
void	error_exit(t_stack *stack);

// swap
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

// push
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a);

// rotate
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

// reverse rotate
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// short sort
void	sort_two_numbers(t_stack *stack_a);
void	sort_three_numbers(t_stack *stack_a);
void	sort_five_numbers(t_stack *stack_a, t_stack *stack_b);

#endif
