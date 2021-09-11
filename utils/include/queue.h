
#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

void				enqueue(t_node **queue, void *data);
void    			dequeue(t_node **queue);
void    			*qpeek(t_node **queue);

#endif