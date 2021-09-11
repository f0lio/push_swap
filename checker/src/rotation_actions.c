
#include "checker.h"

void rotate_a(t_env *env)
{
  rotate_stack(env->a, 1);
}

void rotate_b(t_env *env)
{
  rotate_stack(env->b, 1);
}

void rotate_all(t_env *env)
{
  rotate_a(env);
  rotate_b(env);
}
