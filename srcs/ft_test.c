// commande shell : ARG=$(seq -50 50 | shuf -n 10 | tr '\n' ' ')
// echo "$ARG" | xargs ./push_swap | ./checker_linux $ARG

#include "../includes/ft_push_swap.h"

void test_normalize_stack()
{
    t_stack *stack = init_stack();
    push(stack, 30);
    push(stack, 10);
    push(stack, 20);

    normalize_stack(stack);

    int *normalized_values = get_stack_values(stack);

    printf("test_normalize_stack: ");
    if (normalized_values)
    {
        if (normalized_values[0] == 2 && normalized_values[1] == 0 && normalized_values[2] == 1)
            printf("PASSED\n");
        else
            printf("FAILED\n");
        free(normalized_values);
    } else
        printf("test_normalize_stack: FAILED\n");
    free_stack(stack);
}

void test_sort_bit()
{
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();

    push(stack_a, 2); // 10 en binaire
    push(stack_a, 3); // 11 en binaire
    push(stack_a, 1); // 01 en binaire
    push(stack_a, 0); // 00 en binaire

    sort_bit(stack_a, stack_b, 0);

    int *sorted_values = get_stack_values(stack_a);

    printf("test_sort_bit: ");
    if (sorted_values)
    {
        if (sorted_values[0] == 2 && sorted_values[1] == 0
            && sorted_values[2] == 3 && sorted_values[3] == 1)
            printf("PASSED\n");
        else
            printf("FAILED\n");
    }
    else
        printf("test_sort_bit: FAILED\n");
    free_stack(stack_a);
    free_stack(stack_b);
}

void test_get_stack_values()
{
    t_stack *stack = init_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    int *values = get_stack_values(stack);
    if (values)
    {
        printf("test_get_stack_values: ");
        if (values[0] == 10 && values[1] == 20 && values[2] == 30)
            printf("PASSED\n");
        else
            printf("FAILED\n");
        free(values);
    }
    else
        printf("test_get_stack_values: FAILED\n");
    free_stack(stack);
}

void test_update_stack_values()
{
    t_stack *stack = init_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    int values[] = {30, 20, 10};
    update_stack_values(stack, values);

    int *updated_values = get_stack_values(stack);
    if (updated_values)
    {
        printf("test_update_stack_values: ");
        if (updated_values[0] == 2 && updated_values[1] == 1 && updated_values[2] == 0)
            printf("PASSED\n");
        else
            printf("FAILED\n");
        free(updated_values);
    } else
        printf("test_update_stack_values: FAILED\n");
    free_stack(stack);
}

void test_sort_array()
{
    int array[] = {3, 1, 4, 2, 5};
    int size = 5;

    sort_array(array, size);

    printf("test_sort_array: ");
    int passed = 1;
    for (int i = 0; i < size - 1; i++) 
    {
        if (array[i] > array[i + 1])
        {
            passed = 0;
            break;
        }
    }
    if (passed)
        printf("PASSED\n");
    else
        printf("FAILED\n");
}

void test_find_max_bits()
{
    t_stack *stack = init_stack();
    push(stack, 10);
    push(stack, 15);
    push(stack, 7);

    int bits = find_max_bits(stack);
    printf("test_find_max_bits: ");
    if (bits == 4) // Maximum value is 15 (1111 in binary, 4 bits)
        printf("PASSED\n");
    else
        printf("FAILED\n");
    free_stack(stack);
}

void test_push()
{
    t_stack *stack = init_stack();
    push(stack, 42);

    printf("test_push: ");
    if (stack->size == 1 && stack->top->value == 42)
        printf("PASSED\n");
    else
        printf("FAILED\n");
    free_stack(stack);
}

void test_push_stack()
{
    t_stack *stack = init_stack();
    push_stack(stack, 10);
    push_stack(stack, 20);

    printf("test_push_stack: ");
    if (stack->size == 2 && stack->top->value == 20 && stack->top->next->value == 10)
        printf("PASSED\n");
    else
        printf("FAILED\n");
    free_stack(stack);
}

int main()
{
	test_normalize_stack();
	test_sort_bit();
    test_get_stack_values();
    test_update_stack_values();
    test_sort_array();
    test_find_max_bits();
    test_push();
    test_push_stack();
	return (0);
}
