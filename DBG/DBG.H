#ifndef _DBG_H
# define _DBG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
// # include "MY_DBG.C"

static size_t  dbg_i = 0;

# define    pass   nothing();
# define    REPi(x) for (int i = 0; i < x; i++)
# define    REPj(x) for (int j = 0; j < x; j++)
# define    REPk(x) for (int k = 0; k < x; k++)

#define     print(s) printf("[%s]\n", s)
//#define println(a, args...) print(a "\n", ##args)

//# define    print(...) printf(__VA_ARGS__), fflush(stdout)

# define    PNT(p) printf("(%f, %f)\n", (float)p->x, (float)p->y)
# define    DN(x) printf("{%f}\n", (double)x)
# define    DC(c) (1, c, 1)
# define    DS(s) write(1, s, strlen(s));
# define    PS(s) \
                printf("%s(%s:%d)\n", __func__,__FILE__, __LINE__);\
                printf("[%s]\n", s);

# define    DSN(s, n) printf("{%s: %f}\n", s, (double)n)
# define    msg(s) printf("[ %s ]\n", s)
# define    count(s) printf("[ %s ] [ %zu ]\n", s, dbg_i++) // __COUNTER__

# define    yo DS("{*YO*}");
# define    hi DS("{*HI*}");
# define    nl DC('\n');
# define    sp write(1, "--------------------------\n", 28);
# define    bye exit(0);

void        ft_exitTime(int argc, char **argv, int lifespan);
void        exitfunc(int sig);
void        debugMem(void *mem);

#endif