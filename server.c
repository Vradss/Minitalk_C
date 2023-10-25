/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:54:13 by vflorez           #+#    #+#             */
/*   Updated: 2023/10/25 17:02:52 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_signal_handler(int signal)
{
    static  int  bit;
    static int  i;

    //i = 0;
    
    //construimos 1 byte(8bits) de informacion binaria
    if(signal == SIGUSR1)
        i |= (0x01 << bit);
    bit++;
    if(bit == 8)
    {
        printf("%c", i);
		bit = 0;
        i = 0;
    }
}

int main(int argc, char* argv[])
{
    int pid;
    
    (void)argv; //lo declaramos ya que no utilizamos vars
    if(argc != 1)
    {
        printf("Wrong format, try again:");

        return 0;
    }
    pid = getpid();
    printf("Process ID (PID) : %d\n", pid);
    printf("Waiting for your awesome message..\n");
    
    signal(SIGUSR1, ft_signal_handler);
    signal(SIGUSR2, ft_signal_handler);
    while(argc == 1)
    {
        pause();
    }
    return(0);
}