
#ifndef LINKED_LIST_H
# define LINKED_LIST_H
# include <stdlib.h>

typedef struct		s_node
{
	void			*data;
	struct s_node	*next;
	// struct s_node	*prev;  //For fast "manipulation"
}					t_node;

t_node				*new_node(void);
void				push_back(t_node **list, void *data);
void				push_front(t_node **list, void *data);
t_node				*get_n_node(t_node *list, int n);

#endif