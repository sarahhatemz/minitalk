/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <salzghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:54:22 by salzghou          #+#    #+#             */
/*   Updated: 2026/03/25 14:29:52 by salzghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"

void    handler(int sig)
{
    static int      bit_position = 0;
    static int      current_char = 0;
    static char     *buffer = NULL;
    static int      buf_index = 0;
    char            *tmp;

    if (sig == SIGUSR2)
        current_char |= (1 << bit_position);
    bit_position++;
    if (bit_position == 8)
    {
        if (current_char == '\0')
        {
            if (buffer)
            {
                write(1, buffer, buf_index);
                write(1, "\n", 1);
                free(buffer);
                buffer = NULL;
            }
            buf_index = 0;
        }
        else
        {
            tmp = malloc(buf_index + 2);
            if (!tmp)
                return ;
            if (buffer)
            {
                int j = 0;
                while (j < buf_index)
                {
                    tmp[j] = buffer[j];
                    j++;
                }
                free(buffer);
            }
            tmp[buf_index++] = current_char;
            tmp[buf_index] = '\0';
            buffer = tmp;
        }
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
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return (0);
}