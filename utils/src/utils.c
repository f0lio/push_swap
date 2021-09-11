
#include "env.h"

int     str_len(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

t_bool is_equal(char *s1, char *s2, int i, int limit)
{
    int k;

    k = 0;
    while (i < limit)
        if (s1[k++] != s2[i++])
            return FALSE;
    return TRUE;
}

t_bool  is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (TRUE);
    return (FALSE);
}

t_bool  is_number(char *num)
{
    int     i;
    t_bool  minus;
    

    minus = FALSE;
    i = -1;
    while (num[++i])
    {
        if (num[i] == '-')
        {
            if (minus)
                return FALSE;
            minus = TRUE;
        }
        else if (!is_digit(num[i]))
            return (FALSE);
    }
    return (TRUE);
}

int		str_cmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i))
		i++;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}

int     nbrlen(long long num)
{
    int len;

	len = 0;
	if (num == 0)
		return (1);
	if (num <= 9 && num >= -9)
		return (1);
	if (num < 0 && ++len)
		num = -num;
	while (num && (++len))
		num /= 10;        
    return (len);
}

int get_index(char *src, char delim)
{
    int i;

    i = -1;
    while (src[++i])
        if (src[i] == delim)
            return i;
    return -1;
}

int void_to_int(void *data)
{
    if (data == NULL)
    {
        write(2, "void ptr is NULL\n", 18);
        return -1;
    }
    return (*(int*)data);
}

t_stack    *init_stack(char name)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (stack == NULL)
        return NULL;
    stack->stack = NULL;
    stack->chunks = NULL;
    stack->chunks_count = 0;
    stack->len = 0;
    stack->name = name;
    stack->min = INT32_MAX;
    stack->max = INT32_MIN;
    stack->pivot = 0;
    return stack;
}

void    fill_stack(t_env *env, t_stack *stack)
{
    int    i;

    stack->len = env->size;
    i = 0;
    while (i < env->size)
        push_back(&stack->stack, &env->nums[i++]);
}

t_env   *init_env(void)
{
    t_env *env;

    env = malloc(sizeof(t_env));
    if (!env)
        return NULL;
    env->size = 0;
    env->nums = NULL;
    env->actions = NULL;
    env->a = NULL;
    env->b = NULL;
    return env;
}

t_bool  array_is_sorted(int *arr, int size)
{
    int i;

    size--;
    i = -1;
    while (++i < size)
        if (arr[i] > arr[i + 1])
            return 0;
    return 1;
}

int *dup_int_arr(int *arr, int size)
{
    int *dup;

    if (size < 1)
        return NULL;
    dup = (int*)malloc(size * 4);
    while (--size > -1)
        dup[size] = arr[size];
    return dup;
}
