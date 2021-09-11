
#ifndef STACK_H
# define STACK_H

# include "linked_list.h"

typedef	char		t_bool;
typedef struct		s_stack
{
	char			name;
	int				len;
	t_node			*stack;
	t_node			*chunks;
	int				chunks_count;
	int				min;
	int				max;
	int				pivot;
}					t_stack;

t_stack				*init_stack(char name);
void				push(t_stack *stack, void *data);
void				pop(t_stack *stack);
int					stack_size(t_stack *stack);
t_node				*stack_peek(t_stack *s);
t_bool				stack_isempty(t_stack *stack);
void				swap_stack(t_stack **s);
void				reverse_stack(t_stack *s);
void				rotate_stack(t_stack *s, int k);
void				rrotate_stack(t_stack *s, int k);
int					*stack_to_arr(t_stack *stack, int size);
int					get_steps(t_stack *stack, int number);
void				get_min_max(t_stack *stack);
void				reset_min_max(t_stack *stack);

#endif
