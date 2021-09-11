
#include "checker.h"

char	*str_dup(char *str)
{
	size_t			i;
	size_t			len;
	char			*dup;

	len = str_len(str);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (0);
	dup[len] = 0;
	i = -1;
	while (++i < len)
		dup[i] = str[i];
	return (dup);
}

void    read_instructions(t_env *env)
{
    t_bool  flag;
    char    *line;
    int     ret;

    env->actions = NULL;
    while ((ret = read_line(FD, &line)) > 0)
        push_back(&env->actions, line);
    if (ret == -1)
        _err(env, ERR_READ);
}
