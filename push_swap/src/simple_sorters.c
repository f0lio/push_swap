
#include "push_swap.h"

t_bool solve_simple(t_env *env)
{
    if (env->size == 2 && env->nums[0] > env->nums[1])
        write(1, "sa\n", 3);
    free_mem(env);
    return 0;
}

void    sort_three_nodes_stack(t_env *env, t_stack *stack)
{
    t_node  *list;
    int     a;
    int     b;
    int     c;
    
    list = stack->stack;
    a = void_to_int(((t_node*)get_n_node(list, 0))->data);
    b = void_to_int(((t_node*)get_n_node(list, 1))->data);
    c = void_to_int(((t_node*)get_n_node(list, 2))->data);
    if (a < b && b < c)
        return ;
    else if (a > b && b > c)
    {
        swap_a(env);
        rev_rotate_a(env);
    }
    else if (a > b && b < c && a > c)
        rotate_a(env);
    else if (a < b && b > c && a > c)
        rev_rotate_a(env);
    else if (a < b && b > c)
    {
        swap_a(env);
        rotate_a(env);
    }
    else if (a > b && a < c)
       swap_a(env);
}

void    sort_five_nodes_stack(t_env *env, t_stack *stack)
{
    t_stack *src;
    t_stack *dest;

    src = stack;
    if (src->name == 'A')
        dest = env->b;
    else
        dest = env->a;
    push_to(env, dest->name);
    push_to(env, dest->name);
    if (compare_top_two(dest))
        rotate_this_stack(env, dest->name);
    sort_three_nodes_stack(env, src);
    
    while (is_sorted(src) == FALSE || dest->len)
    {
        if (dest->len == 0)
            rotate_this_stack(env, src->name);
        else if (stack_top(dest) < stack_top(src))
            push_to(env, src->name);
        else if (stack_top(src) < stack_top(dest) && compare_top_two(src))
        {
            rotate_this_stack(env, src->name);
            push_to(env, src->name);
        }
        else
            rotate_this_stack(env, src->name);
        // PRINT_STACKS(2);
    }
    // PRINT_STACKS(2);
}
