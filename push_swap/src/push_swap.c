
#include "push_swap.h"

void print_time(void)
{
    #include <time.h>
    time_t  t;

    time(&t);
    printf("############################\n");
    printf("# %s", ctime(&t));
    printf("############################\n");
}

int     main(int argc, char **argv)
{
    t_env   *env;

    // print_time();
    if (argc < 2)
        return 0;
    env = init_env();
    env->args = argv;
    env->size = argc - 1;
    read_numbers(env);
    if (has_duplicates(env->nums, argc - 1))
        _err(env, ERR_DUP_NUM);
    if (array_is_sorted(env->nums, env->size))
        return 0;
    if (env->size < 3)
        return solve_simple(env);
    env->a = init_stack('A');
    env->b = init_stack('B');
    fill_stack(env, env->a);
    sort_stack(env);
    print_actions(env->actions);
    return (0);
}
