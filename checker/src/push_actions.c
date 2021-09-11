
#include "checker.h"

void  push_a(t_env *env)
{
  if (env->b == NULL)
    return ;
  push(env->a, (int *)env->b->stack->data);
  pop(env->b);
}

void  push_b(t_env *env)
{
  if (env->a == NULL)
    return ;
  push(env->b, (int *)env->a->stack->data);
  pop(env->a);
}
