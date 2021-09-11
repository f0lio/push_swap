
#include "stack.h"

void    push(t_stack *stack, void *data)
{
    push_front(&stack->stack, data);
}

void    pop(t_stack *stack)
{
    t_node *p;

    if (stack == 0 || stack->stack == 0)
        return ;
    p = stack->stack;
    stack->stack = (stack->stack)->next;
    free(p);
}

t_bool  stack_isempty(t_stack *stack)
{
    if (stack == 0)
        return 0;
    return (stack->stack == 0);
}

int     stack_size(t_stack *s)
{
    t_node *iter;
    int   len;

    iter = s->stack;
    len = 0;
    while (iter && ++len)
        iter = iter->next;
    return len;
}

int *stack_to_arr(t_stack *s, int size)
{
    int     i;
    int     *arr;
    t_node   *iter;

    if (size == -1)
        size = stack_size(s);
    arr = (int*)malloc(size * sizeof(int));
    i = -1;
    iter = s->stack;
    while (iter && ++i < size)
    {
        arr[i] = *(int*)iter->data;
        iter = iter->next;
    }
    return (arr);
}

t_node  *stack_peek(t_stack *s)
{
    if (!s || !s->stack)
        return NULL;
    return s->stack;
}

void     reset_min_max(t_stack *stack)
{
    if (stack == NULL)
        return ;
    stack->min = INT8_MAX;
    stack->max = INT8_MIN;
}

void     get_min_max(t_stack *stack)
{
    t_node  *iter;
    int     curr;

    iter = stack->stack;
    while (iter)
    {
        curr = *(int*)(iter->data);
        if (stack->min > curr)
            stack->min = curr;
        if (stack->max < curr)
            stack->max = curr;
        iter = iter->next;
    }
}

