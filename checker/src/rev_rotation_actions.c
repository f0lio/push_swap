
#include "checker.h"

void rev_rotate_a(t_env *env)
{
  rrotate_stack(env->a, 1);
}

void rev_rotate_b(t_env *env)
{
  rrotate_stack(env->b, 1);
}

void rev_rotate_all(t_env *env)
{
  rev_rotate_a(env);
  rev_rotate_b(env);
}
