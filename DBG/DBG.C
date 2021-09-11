
# include "DBG.H"

void exitfunc(int sig)
{
    _exit(0);
}

void    ft_exitTime(int argc, char **argv)
{
    int exitTime;

    exitTime = 10;
    if (argv[1][0] == 't' && argv[1][1] == '=')
        exitTime = atoi(&argv[1][2]);
    signal(SIGALRM, exitfunc);
    alarm(exitTime);
}

bool    nothing() {return 1;}

