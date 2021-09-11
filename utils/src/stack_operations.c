
#include "stack.h"

void  swap_stack(t_stack **s)
{  
    t_node  *stack;
    void    *tmp;

    stack = (*s)->stack;

    if (stack == 0 || (stack)->next == 0)
      return ;
    tmp = (stack)->data; // [5, 4, 3]
    (stack)->data = (stack)->next->data;
    (stack)->next->data = tmp;
}

void reverse_stack(t_stack *s)
{
    t_node  *prev;
    t_node  *current;
    t_node  *next;
    
    if (s->stack == 0)
      return ;
    next = 0;
    current = s->stack;
    prev = 0;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    s->stack = prev;
}

void rotate_stack(t_stack *s, int k)
{
    t_node    *current;
    t_node    *kth_node;
    int       count;

    if (s->stack == 0)
      return ;
    if (k == 0)
        return;
    current = s->stack;
    count = 1;      // k = 1
    while (count++ < k && current)
        current = current->next;
    if (current == 0)
        return ;
    kth_node = current;
    while (current->next)
        current = current->next;
    current->next = s->stack;
    s->stack = kth_node->next;
    kth_node->next = 0;
}
 
void rrotate_stack(t_stack *s, int k)
{
  int     len;
  int     cnt;
	t_node  *tmp;
  t_node  *current;
  t_node  *kth_node;
	
  if (s->stack == 0)
		return ;
  tmp = s->stack;
  len = 1;
	while (tmp->next && len++)
		tmp = tmp->next;
	if (k > len)
		k = k % len;
	k = len - k;
	if (k == 0 || k == len)
		return ;
	current = s->stack;
	cnt = 1;
	while (current && cnt++ < k)
		current = current->next;
	if (current == 0)
		return ;
	kth_node = current;
	tmp->next = s->stack;
	s->stack = kth_node->next;
	kth_node->next = 0;
}

// stack utils
t_bool  is_sorted(t_stack *stack)
{
    t_node  *iter;
    int     prev;
    int     curr;
    if (stack == 0)
        return 0;
    iter = stack->stack;
    prev = *((int*)iter->data);
    iter = iter->next;
    while (iter)
    {
        curr = *((int*)iter->data);
        if (prev > curr)
            return 0;
        prev = curr;
        iter = iter->next;
    }
    return 1;
}
