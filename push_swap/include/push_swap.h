
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "env.h"
# include "DBG.H"

// VERBOSE
# define    VERBOSE          TRUE
# define    LOG_ACTION      FALSE
# define    LOG_STACKS      FALSE
# define    PRINT_DELAY     .2
# define    SWAP_A          push_back(&env->actions, "sa");\
                                LOG_ACTION ? printf("SA\n") : 0;\
                                LOG_STACKS ? PRINT_STACKS(PRINT_DELAY) : 0;
# define    SWAP_B          push_back(&env->actions, "sb");\
                                LOG_ACTION ? printf("SB\n"): 0;\
                                LOG_STACKS ? PRINT_STACKS(PRINT_DELAY) : 0;
# define    PUSH_A          push_back(&env->actions, "pa");\
                                LOG_ACTION ? printf("PA\n") : 0;\
                                LOG_STACKS ? PRINT_STACKS(PRINT_DELAY) : 0;
# define    PUSH_B          push_back(&env->actions, "pb");\
                                LOG_ACTION ? printf("PB\n") : 0;\
                                LOG_STACKS ? PRINT_STACKS(PRINT_DELAY) : 0;
# define    ROTATE_A        push_back(&env->actions, "ra");\
                                LOG_ACTION ? printf("RA\n") : 0;\
                                LOG_STACKS ? PRINT_STACKS(PRINT_DELAY) : 0;
# define    ROTATE_B        push_back(&env->actions, "rb");\
                                LOG_ACTION ? printf("RB\n") : 0;\
                                LOG_STACKS ? PRINT_STACKS(PRINT_DELAY) : 0;
# define    REV_A           push_back(&env->actions, "rra");\
                                LOG_ACTION ? printf("RRA\n") : 0;\
                                LOG_STACKS ? PRINT_STACKS(PRINT_DELAY) : 0;
# define    REV_B           push_back(&env->actions, "rrb");\
                                LOG_ACTION ? printf("RRB\n") : 0;\
                                LOG_STACKS ? PRINT_STACKS(PRINT_DELAY) : 0;

#define     PRINT_STACKS(seconds)    VERBOSE ? usleep(seconds * 1e5), print_stacks(env->a, env->b) : 0
///////////////

t_bool      solve_simple(t_env *env);
void        a_send_to_top(t_env *env, int number, int index);

void        sort_three_nodes_stack(t_env *env, t_stack *stack);
void        sort_five_nodes_stack(t_env *env, t_stack *stack);
void        sort_stack(t_env *env);

void        push_big_nums_to_a(t_env *env);
void        push_big_nums_to_b(t_env *env);
void        fill_a_from_b(t_env *env);

void        print_actions(t_node *actions);

void        sort_array(int *arr, int size, void(*sorting_function)(int *arr, int size));
void        insertion_sort(int *arr, int size);
int         get_median(int *nums, int size);

void        get_pivot(t_env *env, t_stack *stack);
int         get_node_index(t_node *list, t_node *node);
void        push_minimum(t_env *env , t_stack *src, t_stack *dest);

void        push_to(t_env *env, char stack_name);
void        swap_this_stack(t_env *env, char stack_name);
void        rotate_this_stack(t_env *env, char stack_name);
void        rev_rotate_this_stack(t_env *env, char stack_name);

t_bool      compare_top_two(t_stack *stack);
void        filter_a_by_key(t_env *env, int key);


void        stack_to_chunks(t_env *env, t_stack *stack);

#endif