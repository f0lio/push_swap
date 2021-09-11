
#include "push_swap.h"

void    _err(t_env *env, char *msg)
{
    write(1, "Error\n", 6);
    write(1, msg, str_len(msg));
    write(1, "\n", 1);
    free_mem(env);
    exit(EXIT_FAILURE);
}
