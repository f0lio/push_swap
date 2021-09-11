
#include "push_swap.h"

void  swap_all(t_env *env)
{
  swap_a(env);
  swap_b(env);
}

void rev_rotate_all(t_env *env)
{
  rev_rotate_a(env);
  rev_rotate_b(env);
}

void rotate_all(t_env *env)
{
  rotate_a(env);
  rotate_b(env);
}
