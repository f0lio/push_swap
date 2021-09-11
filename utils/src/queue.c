
#include "queue.h"

void    enqueue(t_node **queue, void *data)
{
    push_front(queue, data);
}

void    dequeue(t_node **queue)
{
    t_node *p;

    p = *queue;
    *queue = (*queue)->next;
    free(p);
}

void    *qpeek(t_node **queue)
{
    return (*queue)->data;
}