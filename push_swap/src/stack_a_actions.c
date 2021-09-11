
#include "push_swap.h"

void  swap_this_stack(t_env *env, char stack_name)
{
  if (stack_name == 'A')
    swap_a(env);
  else if (stack_name == 'B')
    swap_b(env);
}

void  swap_a(t_env *env)
{
  swap_stack(&env->a);
  SWAP_A;
}

void  push_a(t_env *env)
{
  t_stack *a;
  t_stack *b;

  a = env->a;
  b = env->b;
  if (a->stack == NULL || b->stack == NULL)
    return ;
  push(a, (int *)b->stack->data);
  pop(b);
  a->len++;
  b->len--;
  PUSH_A;
}

void  rotate_this_stack(t_env *env, char stack_name)
{
  if (stack_name == 'A')
    rotate_a(env);
  else if (stack_name == 'B')
    rotate_b(env);
}

void rotate_a(t_env *env)
{
  rotate_stack(env->a, 1);
  ROTATE_A;
}

void  rev_rotate_this_stack(t_env *env, char stack_name)
{
  if (stack_name == 'A')
    rev_rotate_a(env);
  else if (stack_name == 'B')
    rev_rotate_b(env);
}

void rev_rotate_a(t_env *env)
{
  rrotate_stack(env->a, 1);
  REV_A;
}
