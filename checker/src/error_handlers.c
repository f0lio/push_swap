
#include "checker.h"

void    _err(t_env *env, char *msg)
{
    write(STDERR_FILENO, "Error\n", 6);
    write(STDERR_FILENO, msg, str_len(msg));
    write(STDERR_FILENO, "\n", 1);
    //free_mem
    exit(EXIT_FAILURE);
}

