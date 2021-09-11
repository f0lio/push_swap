
#include "checker.h"


int main(int argc, char **argv)
{
    t_env *env;

    if (argc == 1)
        return 0;
    env = init_env();
    env->a = init_stack('A');
    env->b = init_stack('B');
    env->size = argc - 1;
    env->args = argv;
    read_numbers(env);
    if (has_duplicates(env->nums, env->size))
        _err(env, ERR_DUP_NUM);
    read_instructions(env);
    check_instructions(env);
    fill_stack(env, env->a);
    apply_instructions(env);
    if (!stack_isempty(env->b))
        write(1, "KO\n", 3);
    else if (is_sorted(env->a))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);

    // clean_mem(env);

    /*
    ** -> Check args validity
            +duplicates
            +non-valid chars...
            -bigger than int
            -count, 
    */

    return (0);
}
