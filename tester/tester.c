#include "../includes/ft_push_swap.h"
#include <stdio.h>

void test_no_duplicates() {
    t_stack *stack = init_stack();
    push(stack, 3);
    push(stack, 2);
    push(stack, 1);
    if (is_valid_stack(stack)) {
        printf("test_no_duplicates: PASSED\n");
    } else {
        printf("test_no_duplicates: FAILED\n");
    }
    free_stack(stack);
}

void test_sa() {
    t_stack *stack = init_stack();
    push(stack, 2);
    push(stack, 1); // Stack: 1 -> 2
    sa(stack);      // Expected: 2 -> 1
    if (stack->top->value == 2 && stack->top->next->value == 1) {
        printf("test_sa: PASSED\n");
    } else {
        printf("test_sa: FAILED\n");
    }
    free_stack(stack);
}

void test_sort_two_numbers() {
    t_stack *stack = init_stack();
    push(stack, 2);
    push(stack, 1); // Stack: 1 -> 2
    sort_two_numbers(stack); // Expected: 1 -> 2
    if (stack->top->value == 1 && stack->top->next->value == 2) {
        printf("test_sort_two_numbers: PASSED\n");
    } else {
        printf("test_sort_two_numbers: FAILED\n");
    }
    free_stack(stack);
}

void test_invalid_input() {
    t_stack *stack = init_stack();
    if (!validate_input(4, (char *[]){"./push_swap", "3", "a", "2"}, stack)) {
        printf("test_invalid_input: PASSED\n");
    } else {
        printf("test_invalid_input: FAILED\n");
    }
    free_stack(stack);
}

int main() {
    printf("Starting tests...\n");
    test_no_duplicates();
    test_sa();
    test_sort_two_numbers();
    test_invalid_input();
    printf("All tests completed.\n");
    return 0;
}
