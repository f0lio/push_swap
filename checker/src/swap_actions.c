
#include "checker.h"

void  swap_a(t_env *env)
{
  swap_stack(&env->a);
}

void  swap_b(t_env *env)
{
  swap_stack(&env->b);
}

void  swap_all(t_env *env)
{
  swap_a(env);
  swap_b(env);
}
