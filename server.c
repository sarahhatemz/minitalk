#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"

void    handler(int sig)
{
    static int  bit_position = 0;
    static int  current_char = 0;

    if (sig == SIGUSR2)
        current_char |= (1 << bit_position);
    bit_position++;
    if (bit_position == 8)
    {
        if (current_char != '\0')
            write(1, &current_char, 1);
        bit_position = 0;
        current_char = 0;
    }
}
void    print_pid(int n)
{
    char c;

    if (n > 9)
        print_pid(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

int main()
{
    struct sigaction    sa;

    print_pid(getpid());
    write(1, "\n", 1);
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return (0);
}