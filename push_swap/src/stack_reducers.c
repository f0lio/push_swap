
#include "push_swap.h"

void    push_minimum(t_env *env, t_stack *src, t_stack *dest)
{
    int     index;
    t_node  *iter;
    void    (*action)(t_env*, char);

    get_min_max(src);
    index = get_steps(src, src->min);
    if (index == 0)
        return push_to(env, dest->name);
    if ((src->len - index) < (src->len / 2))
        action = rotate_this_stack;
    else
        action = rev_rotate_this_stack;
    iter = src->stack;
    while (1)
    {
        // print_stacks(src, dest);
        if (src->min == void_to_int(iter->data))
            return push_to(env, dest->name);
        else if (src->min == void_to_int(iter->next->data))
            return swap_this_stack(env, src->name);
        else
        {
            action(env, src->name);
            iter = src->stack;
        }
    }
}

void    push_big_nums_to_a(t_env *env)
{
    t_node   *iter;
    int     curr;
    int     next;
    
    iter = env->b->stack;
    while (iter)
    {
        curr = *((int*)iter->data);
        if (iter->next)
            next = *((int*)iter->next->data);
        else
            break ;
        if (curr > next)
        {
            push_a(env);
            iter = env->b->stack;
            iter = iter->next;
            print_stacks(env->a, env->b);
        }
        else
        {
            swap_b(env);
            push_a(env);
            iter = env->b->stack;
            print_stacks(env->a, env->b);
        }
    }
}

void    push_big_nums_to_b(t_env *env)
{
    t_node  *iter;
    int     curr;
    int     next;
    
    iter = env->a->stack;
    while (iter)
    {
        curr = *((int*)iter->data);
        if (iter->next)
            next = *((int*)iter->next->data);
        else
        {
            push_b(env);
            break ;
        }
        if (curr > next)
        {
            push_b(env);
            iter = env->a->stack;
            iter = iter->next;
            print_stacks(env->a, env->b);
        }
        else
        {
            swap_a(env);
            print_stacks(env->a, env->b);
            push_b(env);
            iter = env->a->stack;
            print_stacks(env->a, env->b);
        }
    }
}

// void    fill_a_from_b(t_env *env)
// {
//     t_node   *iter;
    
//     iter = env->b->stack;
//     while (1)
//     {
//         push_a(env);
//         iter = env->b->stack;
//         if (iter == NULL)
//         {
//             push_a(env);
//             break ;
//         }
//         iter = iter->next;
//         PUSH_A;
//     }
// }
