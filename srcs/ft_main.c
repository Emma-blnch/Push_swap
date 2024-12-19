#include "../includes/ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (ft_printf("Error\n"), 1);
	stack_a = init_stack();
	if (!stack_a)
		return (ft_printf("Error\n"), 1);
	if (!validate_input(argc, argv, stack_a))
		error_exit(stack_a);
	stack_b = init_stack();
	if (!stack_b)
		return (ft_printf("Error\n"), 1);
	choose_sort_algo(stack_a, stack_b);
	return (free_stack(stack_a), free_stack(stack_b), 0);
}
