
#include "push_swap.h"

void stack_to_chunks(t_env *env, t_stack *stack)
{
    int     *sorted;
    int     i;
    int     j;
    int     k;
    int     chunk_size;
    t_stack *chunk;


    stack->chunks_count = 1;
    if (stack->len > 90 && stack->len < 120)
        stack->chunks_count = 5;
    sorted = dup_int_arr(env->nums, stack->len);
    sort_array(sorted, stack->len, insertion_sort);

    chunk_size = stack->len / stack->chunks_count;
    // printf("[SIZE:  %d]\n", chunk_size);
    i = 0;
    k = 0;
    while (i < stack->chunks_count && k < stack->len)
    {
        chunk = init_stack('C');
        push_back(&stack->chunks, chunk);
        j = 0;
        while (j++ < chunk_size || (i == stack->chunks_count - 1 && k < stack->len))
            push_back(&chunk->stack, (void*)&sorted[k++]);
        printf("\n");
        i++;
    }
    printf("\n\n");

    t_node  *chunk_iter,
            *iter;
    chunk_iter = stack->chunks;
    while (chunk_iter)
    {
        iter = ((t_stack*)chunk_iter)->stack;
        while (iter)
        {
            printf("%d ", void_to_int(iter->data));
            iter = iter->next;
        }
        printf("\n");
        chunk_iter = chunk_iter->next;
    }
}
