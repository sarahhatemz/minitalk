/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salzghou <salzghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:48:33 by salzghou          #+#    #+#             */
/*   Updated: 2026/03/25 15:04:07 by salzghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "minitalk.h"
int main(int argc, char **argv)
{
   
    if (argc != 3)
    {
        write(1, "Usage: ./client [PID] [message]\n", 32);
        return (1);
    }
    
    int server_pid = atoi(argv[1]);
    int i = 0;

    if (kill(server_pid, 0) == -1)
    {
        write(1, "Error: invalid PID\n", 19);
        return (1);
    }
    while (argv[2][i])
    {
        int bit = 0;
        while (bit < 8)
        {
            if ((argv[2][i] >> bit) & 1)
                kill(server_pid, SIGUSR2);
            else
                kill(server_pid, SIGUSR1);
            usleep(1000);
            bit++;
        }
        i++;
    }
    int bit = 0;
    while (bit < 8)
    {
        kill(server_pid, SIGUSR1);
        usleep(500);
        bit++;
    }
    return (0);
}
