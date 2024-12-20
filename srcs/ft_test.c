// commande shell : ARG=$(seq -50 50 | shuf -n 10 | tr '\n' ' ')
// echo "$ARG" | xargs ./push_swap | ./checker_linux $ARG

#include "../includes/ft_push_swap.h"

// useful
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

// tests
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

void test_smart_rotate()
{
    t_stack *stack = init_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    smart_rotate(stack, 2); // Devrait effectuer 2 rotations vers le haut (RA)

    printf("test_smart_rotate: ");
    int *values = get_stack_values(stack);
    if (values)
    {
        if (values[0] == 30 && values[1] == 40 && values[2] == 10 && values[3] == 20)
            printf("PASSED\n");
        else
            printf("FAILED\n");
        free(values);
    }
    else
        printf("FAILED (null pointer)\n");
    free_stack(stack);
}

void test_find_insert_position()
{
    printf("test_find_insert_position:\n");

    // Cas 1 : Pile vide
    t_stack *stack = init_stack();
    int pos = find_insert_position(stack, 10);
    printf("  Case 1 (empty stack): ");
    if (pos == 0) {
        printf("PASSED\n");
    } else {
        printf("FAILED (expected 0, got %d)\n", pos);
    }

    free_stack(stack);

    // Cas 2 : Insérer un élément plus petit que tous les éléments existants
    stack = init_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    pos = find_insert_position(stack, 5); // Devrait retourner 0 (avant 10)
    printf("  Case 2 (insert before all): ");
    if (pos == 0) {
        printf("PASSED\n");
    } else {
        printf("FAILED (expected 0, got %d)\n", pos);
    }

    // Cas 3 : Insérer un élément plus grand que tous les éléments existants
    pos = find_insert_position(stack, 40); // Devrait retourner 3 (après 30)
    printf("  Case 3 (insert after all): ");
    if (pos == 3) {
        printf("PASSED\n");
    } else {
        printf("FAILED (expected 3, got %d)\n", pos);
    }

    // Cas 4 : Insérer un élément au milieu
    pos = find_insert_position(stack, 25); // Devrait retourner 2 (entre 20 et 30)
    printf("  Case 4 (insert in the middle): ");
    if (pos == 2) {
        printf("PASSED\n");
    } else {
        printf("FAILED (expected 2, got %d)\n", pos);
    }

    // Cas 5 : Tous les éléments identiques dans la pile
    free_stack(stack);
    stack = init_stack();
    push(stack, 10);
    push(stack, 10);
    push(stack, 10);

    pos = find_insert_position(stack, 10); // Devrait retourner 0 (avant le premier 10)
    printf("  Case 5 (all elements identical): ");
    if (pos == 0) {
        printf("PASSED\n");
    } else {
        printf("FAILED (expected 0, got %d)\n", pos);
    }

    // Cas 6 : Insérer dans une pile avec un seul élément
    free_stack(stack);
    stack = init_stack();
    push(stack, 10);

    pos = find_insert_position(stack, 5); // Devrait retourner 0 (avant 10)
    printf("  Case 6.1 (single element, insert before): ");
    if (pos == 0) {
        printf("PASSED\n");
    } else {
        printf("FAILED (expected 0, got %d)\n", pos);
    }

    pos = find_insert_position(stack, 15); // Devrait retourner 1 (après 10)
    printf("  Case 6.2 (single element, insert after): ");
    if (pos == 1) {
        printf("PASSED\n");
    } else {
        printf("FAILED (expected 1, got %d)\n", pos);
    }

    // Cas 7 : Test precis
    free_stack(stack);
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();
    push(stack_a, 5);
    push(stack_a, 15);
    push(stack_a, 25);
    push(stack_b, 20);
    push(stack_b, 10);

    pos = find_insert_position(stack_a, 20); // Devrait retourner 2 (avant 25)
    printf("  Case 7.1 (single element, insert before): ");
    if (pos == 2) {
        printf("PASSED\n");
    } else {
        printf("FAILED (expected 0, got %d)\n", pos);
    }

    pos = find_insert_position(stack, 10); // Devrait retourner 1 (après 5)
    printf("  Case 7.2 (single element, insert after): ");
    if (pos == 1) {
        printf("PASSED\n");
    } else {
        printf("FAILED (expected 1, got %d)\n", pos);
    }
    free_stack(stack);
}

void test_move_chunk_to_b()
{
    printf("test_move_chunk_to_b:\n");

    // Cas 1 : Piles vides
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();

    move_chunk_to_b(stack_a, stack_b, 10, 20);
    printf("  Case 1 (empty stacks): ");
    if (stack_a->size == 0 && stack_b->size == 0) {
        printf("PASSED\n");
    } else {
        printf("FAILED (stack sizes incorrect)\n");
    }

    free_stack(stack_a);
    free_stack(stack_b);

    // Cas 2 : Aucun élément dans le chunk
    stack_a = init_stack();
    stack_b = init_stack();
    push(stack_a, 5);
    push(stack_a, 25);
    push(stack_a, 30);

    move_chunk_to_b(stack_a, stack_b, 10, 20);
    printf("  Case 2 (no elements in chunk): ");
    if (stack_a->size == 3 && stack_b->size == 0) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    free_stack(stack_a);
    free_stack(stack_b);

    // Cas 3 : Tous les éléments dans le chunk
    stack_a = init_stack();
    stack_b = init_stack();
    push(stack_a, 15);
    push(stack_a, 12);
    push(stack_a, 18);

    move_chunk_to_b(stack_a, stack_b, 10, 20);
    printf("  Case 3 (all elements in chunk): ");
    if (stack_a->size == 0 && stack_b->size == 3) {
        int *values_b = get_stack_values(stack_b);
        if (values_b[0] == 18 && values_b[1] == 12 && values_b[2] == 15) { // L'ordre dépend de votre logique
            printf("PASSED\n");
        } else {
            printf("FAILED (incorrect stack B values)\n");
        }
        free(values_b);
    } else {
        printf("FAILED (stack sizes incorrect)\n");
    }

    free_stack(stack_a);
    free_stack(stack_b);

    // Cas 4 : Quelques éléments dans le chunk
    stack_a = init_stack();
    stack_b = init_stack();
    push(stack_a, 25);
    push(stack_a, 15);
    push(stack_a, 5);
    push(stack_a, 10);

    move_chunk_to_b(stack_a, stack_b, 10, 20);
    printf("  Case 4 (some elements in chunk): ");
    if (stack_a->size == 2 && stack_b->size == 2) {
        int *values_a = get_stack_values(stack_a);
        int *values_b = get_stack_values(stack_b);
        if (values_a && values_b &&
            values_a[0] == 25 && values_a[1] == 5 &&
            values_b[0] == 10 && values_b[1] == 15) {
            printf("PASSED\n");
        } else {
            printf("FAILED (incorrect stack values)\n");
        }
        free(values_a);
        free(values_b);
    } else {
        printf("FAILED (stack sizes incorrect)\n");
    }

    free_stack(stack_a);
    free_stack(stack_b);

    // Cas 5 : Un seul élément dans le chunk
    stack_a = init_stack();
    stack_b = init_stack();
    push(stack_a, 8);
    push(stack_a, 16);
    push(stack_a, 22);

    move_chunk_to_b(stack_a, stack_b, 15, 20); // 16 est dans le chunk
    printf("  Case 5 (one element in chunk): ");
    if (stack_a->size == 2 && stack_b->size == 1) {
        int *values_a = get_stack_values(stack_a);
        int *values_b = get_stack_values(stack_b);
        if (values_a && values_b &&
            values_a[0] == 8 && values_a[1] == 22 &&
            values_b[0] == 16) {
            printf("PASSED\n");
        } else {
            printf("FAILED (incorrect stack values)\n");
        }
        free(values_a);
        free(values_b);
    } else {
        printf("FAILED (stack sizes incorrect)\n");
    }

    free_stack(stack_a);
    free_stack(stack_b);
}

void test_move_chunk_back_to_a()
{
    printf("test_move_chunk_back_to_a:\n");

    // Cas 1 : Piles vides
    t_stack *stack_a = init_stack();
    t_stack *stack_b = init_stack();

    move_chunk_back_to_a(stack_a, stack_b);
    printf("  Case 1 (empty stacks): ");
    if (stack_a->size == 0 && stack_b->size == 0) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    free_stack(stack_a);
    free_stack(stack_b);

    // Cas 2 : Un seul élément dans stack_b
    stack_a = init_stack();
    stack_b = init_stack();
    push(stack_b, 10);

    move_chunk_back_to_a(stack_a, stack_b);
    printf("  Case 2 (one element in stack_b): ");
    if (stack_a->size == 1 && stack_b->size == 0 && stack_a->top->value == 10) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
    }

    free_stack(stack_a);
    free_stack(stack_b);

    // Cas 3 : Plusieurs éléments dans stack_b
    stack_a = init_stack();
    stack_b = init_stack();
    push(stack_a, 5);
    push(stack_a, 15);
    push(stack_a, 25);
    push(stack_b, 20);
    push(stack_b, 10);

    move_chunk_back_to_a(stack_a, stack_b);
    printf("  Case 3 (multiple elements in stack_b): ");
    if (stack_a->size == 5 && stack_b->size == 0) {
        int *values = get_stack_values(stack_a);
        if (values && values[0] == 5 && values[1] == 10 && values[2] == 15 && values[3] == 20 && values[4] == 25) {
            printf("PASSED\n");
        } else {
            printf("FAILED (incorrect order in stack_a)\n");
        }
        free(values);
    } else {
        printf("FAILED (stack sizes incorrect)\n");
    }

    free_stack(stack_a);
    free_stack(stack_b);

    // Cas 4 : Stack_b avec des éléments plus grands que tous ceux de stack_a
    stack_a = init_stack();
    stack_b = init_stack();
    push(stack_a, 1);
    push(stack_a, 2);
    push(stack_b, 3);
    push(stack_b, 4);

    move_chunk_back_to_a(stack_a, stack_b);
    printf("  Case 4 (elements larger than stack_a): ");
    if (stack_a->size == 4 && stack_b->size == 0) {
        int *values = get_stack_values(stack_a);
        if (values && values[0] == 1 && values[1] == 2 && values[2] == 3 && values[3] == 4) {
            printf("PASSED\n");
        } else {
            printf("FAILED (incorrect order in stack_a)\n");
        }
        free(values);
    } else {
        printf("FAILED (stack sizes incorrect)\n");
    }

    free_stack(stack_a);
    free_stack(stack_b);
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
    test_smart_rotate();
    test_find_insert_position();
    test_move_chunk_to_b();
    test_move_chunk_back_to_a();
	return (0);
}
