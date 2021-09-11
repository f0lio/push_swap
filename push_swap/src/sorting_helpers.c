
#include "push_swap.h"

int get_median(int *nums, int size)
{
    int *sorted;
    int med;

    med = -1;
    sorted = dup_int_arr(nums, size);
    insertion_sort(sorted, size);
    // sort_array(sorted, size, insertion_sort);

    med = sorted[(size / 2) - 1];
    free(sorted);
    return med;
}

void    get_pivot(t_env *env, t_stack *s)
{
    int size;
    int *nums;

    size = stack_size(s);
    nums = stack_to_arr(s, size);
    insertion_sort(nums, size);
    // sort_array(nums, size, insertion_sort);
    s->pivot = get_median(nums, size);
}

int     get_steps(t_stack *stack, int number)
{
    t_node *iter;
    int     steps;

    iter = stack->stack;
    steps = 0;
    while (iter)
    {
        if (number == void_to_int(iter->data))
            break;
        steps++;
        iter = iter->next;
    }
    return steps;
}

t_bool  compare_top_two(t_stack *stack)
{
    return (void_to_int(get_n_node(stack->stack, 0)->data) >
            void_to_int(get_n_node(stack->stack, 1)->data));
}

// int     get_steps(t_node *list, int number)
// {
//     int     index;
//     t_node  *iter;

//     if (!list)
//         return -1;
//     index = 0;
//     iter = list;
//     while (iter)
//     {
//         if (void_to_int(iter->data) == number)
//             return index;
//         iter = iter->next;
//         index++;
//     }
//     return -1;
// }

