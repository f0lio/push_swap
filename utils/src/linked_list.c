
#include "linked_list.h"

t_node	*new_node(void)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	node->data = 0;
	node->next = 0;
	return (node);
}

void	push_back(t_node **list, void *data)
{
	t_node	*new;
	t_node	*tmp;

	new = new_node();
	if (!new)
		return ;
	new->data = data;
	if (*list == 0)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next != 0)
		tmp = tmp->next;
	tmp->next = new;
}

void	push_front(t_node **list, void *data)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node)); //protection? -_-
	new->data = data;
	new->next = 0;
	if (*list == 0)
		*list = new;
	else
	{
		new->next = *list;
		*list = new;
	}
}

t_node	*get_n_node(t_node *list, int n)
{
    t_node *iter;
    t_node *node;

    node = NULL;
    if (n < 0)
        return (NULL);
    if (n == 0)
        return list;
    iter = list;
    while (n && iter)
    {
        iter = iter->next;
        n--;
        if (n == 0)
            break ;
    }
    return iter;
}
