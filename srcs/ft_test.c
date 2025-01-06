#include "../includes/ft_push_swap.h"

#define ITALIC "\033[3m"
#define RESET "\033[0m"

// operations whitout print
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
}

void	sa(t_stack *stack_a)
{
	t_node	*temp;

	if (!stack_a || stack_a->size < 2)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	temp->next = stack_a->top->next;
	stack_a->top->next = temp;
}

void	sb(t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_b || stack_b->size < 2)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	temp->next = stack_b->top->next;
	stack_b->top->next = temp;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	ra(t_stack *stack_a)
{
	t_node	*last;
	t_node	*temp;

	if (!stack_a || stack_a->size < 2)
		return ;
	temp = stack_a->top;
	last = stack_a->top;
	while (last->next)
		last = last->next;
	stack_a->top = temp->next;
	last->next = temp;
	temp->next = NULL;
}

void	rb(t_stack *stack_b)
{
	t_node	*last;
	t_node	*temp;

	if (!stack_b || stack_b->size < 2)
		return ;
	temp = stack_b->top;
	last = stack_b->top;
	while (last->next)
		last = last->next;
	stack_b->top = temp->next;
	last->next = temp;
	temp->next = NULL;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack *stack_a)
{
	t_node	*last;
	t_node	*prev;

	if (!stack_a || stack_a->size < 2)
		return ;
	prev = NULL;
	last = stack_a->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack_a->top;
	stack_a->top = last;
}

void	rrb(t_stack *stack_b)
{
	t_node	*last;
	t_node	*prev;

	if (!stack_b || stack_b->size < 2)
		return ;
	prev = NULL;
	last = stack_b->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack_b->top;
	stack_b->top = last;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

// imprimer resultats des tests
void print_test_result(int passed, const char *test_name, const char *description)
{
    if (passed)
        printf("%s %s%s%s: ✅ PASSED\n", test_name, ITALIC, description, RESET);
    else
        printf("%s %s%s%s: ❌ FAILED\n", test_name, ITALIC, description, RESET);
}

// tests
void test_normalize_stack()
{
    t_stack *stack = init_stack();

    // Test with a basic stack
    push(stack, 30);
    push(stack, 10);
    push(stack, 20);
    normalize_stack(stack);

    int *normalized_values = get_stack_values(stack);
    int passed = normalized_values && normalized_values[0] == 2 
                 && normalized_values[1] == 0 
                 && normalized_values[2] == 1;
    print_test_result(passed, "test_normalize_stack", "(basic stack)");
    free(normalized_values);

    // Test with already normalized stack
    free_stack(stack);
    stack = init_stack();
    push(stack, 1);
    push(stack, 0);
    normalize_stack(stack);

    normalized_values = get_stack_values(stack);
    passed = normalized_values && normalized_values[0] == 1 && normalized_values[1] == 0;
    print_test_result(passed, "test_normalize_stack", "(already normalized stack)");
    free(normalized_values);

    free_stack(stack);
}

void test_sort_bit()
{
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();

    // Test sorting with least significant bit
    push(stack_a, 2); // 10 en binaire
    push(stack_a, 3); // 11 en binaire
    push(stack_a, 1); // 01 en binaire
    push(stack_a, 0); // 00 en binaire
    sort_bit(stack_a, stack_b, 0);

    int *sorted_values = get_stack_values(stack_a);
    int passed = sorted_values && sorted_values[0] == 2 && sorted_values[1] == 0 
                 && sorted_values[2] == 3 && sorted_values[3] == 1;
    print_test_result(passed, "test_sort_bit", "(LSB sorting)");
    free(sorted_values);

    // Test sorting with most significant bit
    sort_bit(stack_a, stack_b, 1);
    sorted_values = get_stack_values(stack_a);
    passed = sorted_values && sorted_values[0] == 0 && sorted_values[1] == 1
             && sorted_values[2] == 2 && sorted_values[3] == 3;
    print_test_result(passed, "test_sort_bit", "(MSB sorting)");
    free(sorted_values);

    free_stack(stack_a);
    free_stack(stack_b);
}

void test_get_stack_values()
{
    t_stack *stack = init_stack();

    // Test with multiple values
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    int *values = get_stack_values(stack);
    int passed = values && values[0] == 10 && values[1] == 20 && values[2] == 30;
    print_test_result(passed, "test_get_stack_values", "(multiple values)");
    free(values);

    // Test with empty stack
    free_stack(stack);
    stack = init_stack();
    values = get_stack_values(stack);
    passed = values == NULL;
    print_test_result(passed, "test_get_stack_values", "(empty stack)");

    free_stack(stack);
}

void test_update_stack_values()
{
    t_stack *stack = init_stack();

    // Test updating values
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    int values[] = {30, 20, 10};
    update_stack_values(stack, values);

    int *updated_values = get_stack_values(stack);
    int passed = updated_values && updated_values[0] == 2 
                 && updated_values[1] == 1 
                 && updated_values[2] == 0;
    print_test_result(passed, "test_update_stack_values", "(update values)");
    free(updated_values);

    // Test with empty stack
    free_stack(stack);
    stack = init_stack();
    update_stack_values(stack, values); // Should not crash
    passed = is_valid_stack(stack) == 1;
    print_test_result(passed, "test_update_stack_values", "(empty stack)");

    free_stack(stack);
}

void test_sort_array()
{
    // Test with an unsorted array
    int array1[] = {3, 1, 4, 2, 5};
    int size1 = 5;
    sort_array(array1, size1);
    int passed = 1;
    for (int i = 0; i < size1 - 1; i++) {
        if (array1[i] > array1[i + 1]) {
            passed = 0;
            break;
        }
    }
    print_test_result(passed, "test_sort_array", "(unsorted array)");

    // Test with an already sorted array
    int array2[] = {1, 2, 3, 4, 5};
    int size2 = 5;
    sort_array(array2, size2);
    passed = 1;
    for (int i = 0; i < size2 - 1; i++) {
        if (array2[i] > array2[i + 1]) {
            passed = 0;
            break;
        }
    }
    print_test_result(passed, "test_sort_array", "(already sorted array)");
}

void test_find_max_bits()
{
    t_stack *stack = init_stack();

    // Test with non-empty stack
    push(stack, 10);
    push(stack, 15);
    push(stack, 7);
    int bits = find_max_bits(stack);
    print_test_result(bits == 4, "test_find_max_bits", "(non-empty stack)");

    // Test with empty stack
    free_stack(stack);
    stack = init_stack();
    bits = find_max_bits(stack);
    print_test_result(bits == 0, "test_find_max_bits", "(empty stack)");

    free_stack(stack);
}

void test_push()
{
    t_stack *stack = init_stack();

    // Test single push
    push(stack, 42);
    int passed = stack->size == 1 && stack->top->value == 42;
    print_test_result(passed, "test_push", "(single push)");

    // Test multiple pushes
    push(stack, 24);
    push(stack, 84);
    passed = stack->size == 3 && stack->top->value == 84;
    print_test_result(passed, "test_push", "(multiple pushes)");

    free_stack(stack);
}

void test_push_stack()
{
    t_stack *stack = init_stack();

    // Test pushing multiple values
    push_stack(stack, 10);
    push_stack(stack, 20);
    int passed = stack->size == 2 && stack->top->value == 20 && stack->top->next->value == 10;
    print_test_result(passed, "test_push_stack", "(multiple pushes)");

    // Test with an empty stack
    free_stack(stack);
    stack = init_stack();
    passed = stack->size == 0;
    print_test_result(passed, "test_push_stack", "(empty stack)");

    free_stack(stack);
}

void test_is_sorted()
{
    t_stack *stack = init_stack();

    // Test with empty stack
    print_test_result(is_sorted(stack) == 1, "test_is_sorted", "(empty stack)");

    // Test with sorted stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    print_test_result(is_sorted(stack) == 1, "test_is_sorted", "(sorted stack)");

    // Test with unsorted stack
    push(stack, 5);
    print_test_result(is_sorted(stack) == 0, "test_is_sorted", "(unsorted stack)");

    free_stack(stack);
}

void test_find_minimum()
{
    t_stack *stack = init_stack();
    push(stack, 30);
    push(stack, 10);
    push(stack, 20);

    int min = find_minimum(stack);
    print_test_result(min == 10, "test_find_minimum", "(correct minimum value)");

    free_stack(stack);
}

void test_find_maximum()
{
    t_stack *stack = init_stack();
    push(stack, 30);
    push(stack, 10);
    push(stack, 20);

    int max = find_maximum(stack);
    print_test_result(max == 30, "test_find_maximum", "(correct maximum value)");

    free_stack(stack);
}

void test_find_value_position()
{
    t_stack *stack = init_stack();
    push(stack, 30);
    push(stack, 10);
    push(stack, 20);

    int pos = find_value_position(stack, 10);
    print_test_result(pos == 1, "test_find_value_position", "(value exists)");

    pos = find_value_position(stack, 50);
    print_test_result(pos == 3, "test_find_value_position", "(value does not exist)");

    free_stack(stack);
}

void test_validate_input()
{
    t_stack *stack = init_stack();
    char *args[] = {"program", "10", "20", "30", NULL};

    int valid = validate_input(4, args, stack);
    print_test_result(valid == 1, "test_validate_input", "(valid input)");

    char *invalid_args[] = {"program", "10", "20", "10", NULL};
    valid = validate_input(4, invalid_args, stack);
    print_test_result(valid == 0, "test_validate_input", "(invalid input)");

    free_stack(stack);
}

void test_is_valid_stack()
{
    t_stack *stack = init_stack();

    // Test valid stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    print_test_result(is_valid_stack(stack) == 1, "test_is_valid_stack", "(valid stack)");

    // Test invalid stack with duplicate values
    push(stack, 10);
    print_test_result(is_valid_stack(stack) == 0, "test_is_valid_stack", "(invalid stack with duplicate values)");

    // Test empty stack
    free_stack(stack);
    stack = init_stack();
    print_test_result(is_valid_stack(stack) == 0, "test_is_valid_stack", "(empty stack)");

    // Test single element stack
    push(stack, 42);
    print_test_result(is_valid_stack(stack) == 1, "test_is_valid_stack", "(single element stack)");

    free_stack(stack);
}

int main()
{
    printf("           --- Test normalize_stack ---\n");
	test_normalize_stack();
    printf("\n");
    printf("           --- Test sort_bit ---\n");
	test_sort_bit();
    printf("\n");
    printf("           --- Test get_stack_values ---\n");
    test_get_stack_values();
    printf("\n");
    printf("           --- Test update_stack_values ---\n");
    test_update_stack_values();
    printf("\n");
    printf("           --- Test sort_array ---\n");
    test_sort_array();
    printf("\n");
    printf("           --- Test find_max_bits ---\n");
    test_find_max_bits();
    printf("\n");
    printf("           --- Test push ---\n");
    test_push();
    printf("\n");
    printf("           --- Test push_stack ---\n");
    test_push_stack();
    printf("\n");
    printf("           --- Test is_sorted ---\n");
    test_is_sorted();
    printf("\n");
    printf("           --- Test find_minimum ---\n");
    test_find_minimum();
    printf("\n");
    printf("           --- Test find_maximum ---\n");
    test_find_maximum();
    printf("\n");
    printf("           --- Test find_value_position ---\n");
    test_find_value_position();
    printf("\n");
    printf("           --- Test validate_input ---\n");
    test_validate_input();
    printf("\n");
    printf("           --- Test is_valid_stack ---\n");
    test_is_valid_stack();
    printf("\n");
	return (0);
}
