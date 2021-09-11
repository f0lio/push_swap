
#include "push_swap.h"

void    filter_by_number(t_env *env, t_stack *src, t_stack *dest, int key)
{

}

void    filter_a_by_key(t_env *env, int key)
{
    t_node *iter;
    t_bool  index;

    iter = env->a->stack;
    index = 0;
    while (iter)
    {
        // print_stacks(env->a, env->b);
        printf("%d < %d\n", void_to_int(iter->data), key);
        sleep(1);
        if (void_to_int(iter->data) < key)
        {
            yo;
            if (index == 0)
            {
                push_a(env);
                print_stacks(env->a, env->b);
                print("IF");
            }
            else
            {
                a_send_to_top(env, void_to_int(iter->data), index);
                push_a(env); 
                print("ELSE");
            }
            iter = env->a->stack;
            index = 0;
            continue ;
        }
        index++;
        iter = iter->next;
    }
}

