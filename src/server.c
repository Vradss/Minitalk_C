/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:54:13 by vflorez           #+#    #+#             */
/*   Updated: 2023/10/31 13:31:09 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal_handler(int signal)
{
	static int		bit;
	static int		i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[91mWrong format\033[0m\n");
		ft_printf("\033[96mtry this : ./server \033[0m\n");
		return (0);
	}
	pid = getpid();
	ft_printf("\033[96mProcess ID (PID)\033[0m --> \033[91m%d\n\033[0m", pid);
	ft_printf("\033[90mWaiting for your awesome message..\033[0m\n");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_signal_handler);
		signal(SIGUSR2, ft_signal_handler);
		pause();
	}
	return (0);
}
