#include "../includes/ft_push_swap.h"

void    sort_two_numbers(t_stack *stack_a)
{
    if (!stack_a || stack_a->size < 2)
        return ;
    if (stack_a->top->value > stack_a->top->next->value)
        sa(stack_a);
}

void    sort_three_numbers(t_stack *stack_a)
{
    t_node  *last;

    if (!stack_a || stack_a->size < 3)
        return ;
    last = ft_lstlast(stack_a);
    if (stack_a->top->value > stack_a->top->next->value)
        sa(stack_a);
    if (stack_a->top->next->value > last->value)
        ra(stack_a);
}
