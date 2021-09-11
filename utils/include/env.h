
#ifndef ENV_H
# define ENV_H

# include "basic_includes.h"
# include "linked_list.h"
# include "stack.h"

#ifndef INT32_MAX
# define INT32_MAX 2147483647
#endif

#ifndef INT32_MIN
# define INT32_MIN (-INT32_MAX-1)
#endif

# define    ERR_INVLD_ARG   "All arguments must be intergers!"
# define    ERR_DUP_NUM     "Numbers must not contain any duplicates"
# define    ERR_READ        "FAILED AT READING INPUT"

typedef struct              s_env
{
    int                     size;
    char                    **args;
    int                     *nums;
    t_node                  *actions;
    t_stack                 *a;
    t_stack                 *b;
}                           t_env;

void        swap_a(t_env *env);
void        swap_b(t_env *env);
void        swap_all(t_env *env);
void        push_a(t_env *env);
void        push_b(t_env *env);
void        rotate_a(t_env *env);
void        rotate_b(t_env *env);
void        rotate_all(t_env *env);
void        rev_rotate_a(t_env *env);
void        rev_rotate_b(t_env *env);
void        rev_rotate_all(t_env *env);

t_env      *init_env(void);
void        read_numbers(t_env *env);
int         get_number(t_env *env, int i);
int         str_len(char *str);
t_bool      is_digit(char c);
t_bool      is_number(char *num);
t_bool      is_equal(char *s1, char *s2, int i, int limit);
int		    str_cmp(char *s1, char *s2);
int         str_len(char *str);
int         nbrlen(long long num);
t_bool      has_duplicates(int *nums, int size);
t_bool      is_sorted(t_stack *stack);
int         void_to_int(void *data);
void        _err(t_env *env, char *msg);
t_bool      array_is_sorted(int *arr, int size);

t_bool      is_digit(char c);

void    fill_stack(t_env *env, t_stack *stack);
void    free_mem(t_env *env);
int     *dup_int_arr(int *arr, int size);

/////

void        print_stack(t_stack *s);
void        print_stacks(t_stack *A, t_stack *B);

#endif