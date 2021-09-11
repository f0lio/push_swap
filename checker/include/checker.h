
#ifndef CHECKER_H
# define CHECKER_H

# include "env.h"

# define    FD              1
# define    INSTRUCTIONS    "sa sb ss pa pb ra rb rr rra rrb rrr"
# define    ERR_INVLD_INST  "INVALID INSTRUCTION"
void        read_instructions(t_env *env);
int         read_line(int fd, char **line);
void        check_instructions(t_env *env);
void        apply_instructions(t_env *env);

int         get_index(char *src, char delim);
t_bool      is_included(char *target, char *src, char delim);
t_bool      is_instruction(char *str);


#endif
