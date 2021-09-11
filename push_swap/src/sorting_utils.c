
#include "push_swap.h"

//stack_size() needs to be optimized by updating len on each push_stack() call
void    a_send_to_top(t_env *env, int number, int index)
{
    t_stack *stack;
    int     len;
    int     steps;
    void    (*action)(t_env *);
    
    stack = env->a;
    if (index == 0)
        return ;
    else if (index == -1)
        index = get_steps(stack, number);
    len = stack_size(stack);
    if ((len / 2 ) < index)
        action = &rotate_a;
    else
        action = &rev_rotate_a;
    while (index-- != -1)
        action(env);
}

void        sort_array(int *arr, int size, void(*sorting_function)(int *arr, int size))
{
    sorting_function(arr, size);
}

void    insertion_sort(int *arr, int size)
{
    int i;
    int j;
    int key;

    i = 0;
    while (++i < size)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
