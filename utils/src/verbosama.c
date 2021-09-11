
// TEMPORARY FILE FOR DEBUGGING PURPOSES

#include "env.h"

void    print_actions(t_node *actions)
{
    t_node *iter;

    iter = actions;
    while (iter)
    {
        printf("%s\n", (char*)iter->data);
        iter = iter->next;
    }
}

void    print_stacks(t_stack *A, t_stack *B)
{
    t_node  *a;
    t_node  *b;
    int     a_val;
    int     b_val;

    // if (A == NULL || A->stack == NULL)
    // {
    //     printf("A == NULL\n");
    //     return ;
    // }
    // if (B == NULL || B->stack == NULL)
    // {
    //     printf("B == NULL\n");
    //     return ;
    // }
    a = A->stack;
    b = B->stack;
    printf("\t ____________________________ \n");
    printf("\t|____ %c _____|\t|____ %c _____|\n", 'A', 'B');
    while (a || b)
    {
        a_val = a ? *((int*)a->data) : 0;
        b_val = b ? *((int*)b->data) : 0;
        if (a && b)
        {
            a_val = *((int*)a->data);
            b_val = *((int*)b->data);
            printf("\t[%11d ]\t[%11d ]\n", a_val, b_val);
            a = a->next;
            b = b->next;
        }
        else if (B == NULL || B->stack == NULL)
        {
            a_val = *((int*)a->data);
            printf("\t[%11d ]\t[%11s ]\n", a_val, "NULL");
            a = a->next;
        }
        else if (A == NULL || A->stack == NULL)
        {
            b_val = *((int*)b->data);
            printf("\t[%11s ]\t[%11d ]\n", "NULL", b_val);
            b = b->next;
        }
        else if (a && !b)
        {
            a_val = *((int*)a->data);
            printf("\t[%11d ]\t[%11c ]\n", a_val, ' ');
            a = a->next;
        }
        else
        {
            b_val = *((int*)b->data);
            printf("\t[%11c ]\t[%11d ]\n", ' ', b_val);
            b = b->next;
        }
    }
    printf("\t------------------------------\n");
}

void    print_stack(t_stack *s)
{
    t_node *iter;

    iter = s->stack;
    printf("---------------\n");
    while (iter)
    {
        printf("[%d]\n", *((int*)iter->data));
        iter = iter->next;
    }
    printf("---------------\n");
}
