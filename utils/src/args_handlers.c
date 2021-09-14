
#include "env.h"

#define	ERR_INVLD_ARG	"All arguments must be intergers!"
#define	ERR_INVLD_INST	"Invalid instruction."
#define	ERR_DUP_NUM		"Numbers must not contain any duplicates"

int	get_number(t_env *env, int i)
{
	int		num;
	int		num_len;
	int		arg_len;

	i++;
	if (!is_number(env->args[i]))
		_err(env, ERR_INVLD_ARG);
	num = atoi(env->args[i]);
	num_len = nbrlen(num) + (num < 0);
	arg_len = str_len(env->args[i]);
	if (num_len != arg_len)
		_err(env, ERR_INVLD_ARG);
	return (num);
}

void	read_numbers(t_env *env)
{
	int		i;

	env->nums = (int*)malloc(env->size * sizeof(int));
	i = -1;
	while (++i < env->size)
		env->nums[i] = get_number(env, i);
}

t_bool	has_duplicates(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
			if (nums[i] == nums[j++])
				return (TRUE);
		i++;
	}
	return (FALSE);
}
