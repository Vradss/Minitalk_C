/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vflorez <vflorez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:27:28 by vflorez           #+#    #+#             */
/*   Updated: 2023/10/31 13:38:34 by vflorez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "../src/Printf/ft_printf.h"
# include "../src/libft/libft.h"
# include <stdio.h>

void	get_bits(int pid, char i);
void	ft_signal_handler(int signal);

#endif