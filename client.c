/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradis <vradis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:53:31 by vflorez           #+#    #+#             */
/*   Updated: 2023/10/20 18:02:31 by vradis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bits(int pid, char i)
{
	int bit;

	bit = 0;
	while (bit < 8) // byte = 8 bits
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int main(int argc, char* argv[])
{
	int pid;
	int i;
	
	i = 0;
	
	if(argc == 3)
	{
		pid = atoi(argv[1]);
		while(argv[2][i] != '\0') //recorre todo el mensaje
		{
			get_bits(pid, argv[2][i]); //se envia en bits
			i++;
		}
		get_bits(pid,'\n');
	}
	else
	{
		printf("Wrong Message, try again :");
		return(1);
	}
	return (0);
}