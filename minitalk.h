#ifndef MINITALK_H
# define MINITALK_H

// # include "libft/libft.h"  
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void    print_pid(int n);
void    handler(int sig);
int ft_atoi(const char *nptr);


#endif