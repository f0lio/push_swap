
#include "checker.h"

t_bool  is_included(char *target, char *src, char delim)
{
    int     target_len;
    int     src_len;
    int     index;
    int     i;
    int     j;
    char    c;

    target_len = str_len(target);
    src_len = str_len(src);
    i = 0;
    j = 0;
    while (i < src_len)
    {
        index = get_index(&src[i], delim);
        if (index == -1)
            index = src_len;
        else
            index += i;
        if ((index - i) <= 0 || (index - i) != target_len)
        {
            i = index + 1;
            continue;
        }
        if (is_equal(target, src, i, index))
            return TRUE;
        i = index + 1;
    }
    return FALSE;
}

t_bool  is_instruction(char *str)
{
    int len;

    len = str_len(str);
    if (len != 2 && len != 3)
        return 0;
    return (is_included(str, INSTRUCTIONS, ' '));
}

void    check_instructions(t_env *env)
{
    t_node  *iter;

    iter = env->actions;
    while (iter)
        if (!is_instruction((char*)iter->data))
            _err(env, ERR_INVLD_INST);
        else
            iter = iter->next;
}

void    apply_action(t_env *env, char *action)
{
    if (str_cmp(action, "sa") == 0)
        swap_a(env);
    else if (str_cmp(action, "sb") == 0)
        swap_b(env);
    else if (str_cmp(action, "ss") == 0)
        swap_all(env);
    else if (str_cmp(action, "pa") == 0)
        push_a(env);
    else if (str_cmp(action, "pb") == 0)
        push_b(env);
    else if (str_cmp(action, "ra") == 0)
        rotate_a(env);
    else if (str_cmp(action, "rb") == 0)
        rotate_b(env);
    else if (str_cmp(action, "rr") == 0)
        rotate_all(env);
    else if (str_cmp(action, "rra") == 0)
        rev_rotate_a(env);
    else if (str_cmp(action, "rrb") == 0)
        rev_rotate_b(env);
    else
        rev_rotate_all(env);
}

void    apply_instructions(t_env *env)
{
    t_node  *iter;

    iter = env->actions;
    while (iter)
    {
        apply_action(env, (char*)iter->data);
        iter = iter->next;
    }
}

void    fill_stack_a(t_env *env)
{
    int size;

    size = env->size;
    while (size)
        push(env->a, &env->nums[--size]);
}
