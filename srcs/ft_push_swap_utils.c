#include "../includes/ft_push_swap.h"

// check duplicates
int	is_valid_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*checker;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (0);
			checker = checker->next;
		}
		current = current->next;
	}
	return (1);
}

// free stack
void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while(current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

// check errors
void	error_exit(t_stack *stack)
{
	ft_printf("Error\n");
	free_stack(stack);
	exit(EXIT_FAILURE);
}

// atoi
static int  check_overflow(long result, int sign, char next_digit)
{
    long    test;

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
	long    result;

	sign = 1;
    *is_valid = 0;
    result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-' || *str == '+'))
	{
		if ((*str++ == '-' || *str++ == '+'))
			return (0);
		if (*str == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
        if (check_overflow(result, sign, *str))
        {
            *is_valid = 1;
            return (0);
        }
		result = result * 10 + (*str++ - '0');
	}
	return ((int)result * sign);
}
