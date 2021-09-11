
#include "push_swap.h"

void  push_to(t_env *env, char stack_name)
{
	if (stack_name == 'A')
		push_a(env);
	else if (stack_name == 'B')
		push_b(env);
}

void  swap_b(t_env *env)
{
  swap_stack(&env->b);
  SWAP_B;
}

void  push_b(t_env *env)
{
  t_stack *a;
  t_stack *b;

  a = env->a;
  b = env->b;
  if (a->stack == NULL)
    return ;
  push(b, (int *)a->stack->data);
  pop(a);
  a->len--;
  b->len++;
  PUSH_B;
}

void rotate_b(t_env *env)
{
  rotate_stack(env->b, 1);
  ROTATE_B;
}

void rev_rotate_b(t_env *env)
{
  rrotate_stack(env->b, 1);
  REV_B;
}
