// commande shell : ARG=$(seq -50 50 | shuf -n 10 | tr '\n' ' ')
// echo "$ARG" | xargs ./push_swap | ./checker_linux $ARG

#include "../includes/ft_push_swap.h"

void test_normalize_stack()
{
    t_stack *stack = init_stack();
    push(stack, 4);
    push(stack, 5);
    push(stack, 3);
    push(stack, 2);
    push(stack, 1);
    push(stack, 8);

	printf("Before normalization:\n");
	print_stack(stack);
    normalize_stack(stack);
	printf("after normalization:\n");
    print_stack(stack);
    free_stack(stack);
}

void test_sort_bit()
{
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();
    push(stack_a, 4);
    push(stack_a, 5);
    push(stack_a, 3);
    push(stack_a, 2);
	push(stack_a, 1);
	push(stack_a, 8);

	printf("Before sort_bit:\n");
    print_stack(stack_a);
    sort_bit(stack_a, stack_b, 0); // Trie par le bit le moins significatif
    printf("after sort_bit:\n");
	print_stack(stack_a); // Vérifiez l'ordre.
    print_stack(stack_b); // Vérifiez l'ordre.
    free_stack(stack_a);
    free_stack(stack_b);
}

int main()
{
	// test_normalize_stack();
	test_sort_bit();
	return (0);
}
