
#include "push_swap.h"

void    free_mem(t_env *env)
{
    t_node *iter;

    iter = env->actions;
    while (iter)
    {
        if (iter->data)
            free(iter->data);
        free(iter);
        iter = iter->next;
    }
    if (env->a)
        iter = env->a->stack;
    else
        iter = NULL;
    while (iter)
    {
        if (iter->data)
            free(iter->data);
        free(iter);
        iter = iter->next;
    }
    if (env->a)
        iter = env->b->stack;
    else
        iter = NULL;
    while (iter)
    {
        if (iter->data)
            free(iter->data);
        free(iter);
        iter = iter->next;
    }
    if (env->nums)
        free(env->nums);
}
