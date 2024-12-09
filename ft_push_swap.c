/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <eblancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:36:46 by eblancha          #+#    #+#             */
/*   Updated: 2024/12/09 14:09:24 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack *init_stack(void)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

void    push(t_stack *stack, int value)
{
    t_node  *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return ;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

int is_valid_stack(t_stack *stack)
{
    t_node  *current;
    t_node  *checker;

    current = stack->top;
    while (current)
    {
        checker = current->next;
        while (checker)
        {
            if (current-> value == checker->value)
                return (0);
            checker = checker->next;
        }
        current = current->next;
    }
    return (1);
}

void    print_stack(t_stack *stack)
{
    t_node  *current;

    current = stack->top;
    
    printf("Stack (size: %d):\n", stack->size);
    while (current)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    int i;
    int value;
    
    if (argc < 2)
        return (1);
    stack_a = init_stack();
    if (!stack_a)
        return (1);
    value = 0;
    i = 1;
    while (i < argc)
    {
        value = atoi(argv[i]);
        push(stack_a, value);
        i++;
    }
    if (is_valid_stack(stack_a) == 0)
    {
        printf("Error: stack contains duplicate values\n");
        return (1);
    }
    print_stack(stack_a);
    return (0);
}
