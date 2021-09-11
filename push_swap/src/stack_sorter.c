
#include "push_swap.h"

void    push_all_to(t_env *env, t_stack *dest)
{
    t_stack     *src;
    void        (*action)(t_env *);

    if (dest->name == 'A')
    {
        action = push_a;
        src = env->b;
    }
    else
    {
        action = push_b;
        src = env->a;
    }

    while (src->stack)
        action(env);
}

void    max_to_top(t_env *env, t_stack *stack)
{
    t_node *iter;

    iter = stack->stack;
    while (iter)
        if (void_to_int(iter->data) != stack->max)
        {
            rotate_this_stack(env, stack->name);
            iter = stack->stack;
        }
        else
            break ;
}

int    arrange_stack(t_env *env, t_stack *stack, int num, t_bool reverse)
{
    t_node  *iter; 
    int     curr;
    int     steps;

    steps = 0;
    iter = stack->stack;
    while (iter)
    {
        curr = void_to_int(iter->data);
        if (num > void_to_int(iter->data))
            break ;
        if (reverse)
            rev_rotate_this_stack(env, stack->name);
        else
            rotate_this_stack(env, stack->name);
        iter = stack->stack;
        steps++;
    }
    return (steps);
}

void    sort_stack_a(t_env *env)
{
    t_node  *iter;
    t_stack *a;
    t_stack *b;
    int     curr;
    int     steps;

    a = env->a;
    b = env->b;
    get_min_max(a);    
    //Handle first states of stack_b outside the loop!
    {
        //Making sure B is not NULL before running the following 'expensive' loop
        if (void_to_int(a->stack->data) == a->min)
            rotate_a(env);
        push_b(env);
        //Handling B when it has only one element; cuz rotation in this case is meaningless! 
        {
            //Make sure max_a is not on top!
            if (void_to_int(a->stack->data) == a->min)
                rotate_a(env);
            push_b(env);
            if (void_to_int(b->stack->data) < void_to_int(get_n_node(b->stack, 1)->data))
                rotate_b(env);
        }
    }
    get_min_max(b);
    iter = a->stack;
    steps = 0;
    while (iter)
    {
        iter = a->stack;
        curr = void_to_int(iter->data);
        // printf("* [ %d ,  %d,  %d, %d] *\n",curr, a->min, b->min, void_to_int(b->stack->data));
        // PRINT_STACKS(DELAY);
        if (curr == a->min)
        {
            rotate_a(env);
            continue ;
        }
        else if (curr < b->min)
        {
            b->min = curr;
            push_b(env);
            rotate_b(env);
        }
        else if (curr < void_to_int(b->stack->data))
        {
            steps = arrange_stack(env, b, curr, FALSE);
            push_b(env);
            while (steps--)
                rev_rotate_this_stack(env, b->name);
            steps = 0;
        }
        else
            push_b(env);
        if (a->len == 1)
            break ;
    }
    push_all_to(env, env->a);
    rev_rotate_a(env);
}

void    sort_long_stack(t_env *env, t_stack *stack)
{
    t_node *iter;

    get_min_max(stack);
    iter = stack->stack;
    while (iter)
    {
        if (void_to_int(iter->data) < stack->max)
        {
            ;// push_to()
        }
        iter = iter->next;
    }
}

void    sort_stack(t_env *env)
{
    int pivot;

    if (env->size == 3)
        return sort_three_nodes_stack(env, env->a);
    else if (env->size == 4)
    {
        push_minimum(env, env->a, env->b);
        sort_three_nodes_stack(env, env->a);
        return push_a(env);
    }
    else if (env->size == 5)
        return sort_five_nodes_stack(env, env->a);
    stack_to_chunks(env, env->a);
    // sort_stack_by_chunks(env, env->a);

    // sort_stack_a(env);
}
