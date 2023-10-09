/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:04:10 by mafranco          #+#    #+#             */
/*   Updated: 2023/10/09 20:06:18 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
		{
			kill(pid, SIGUSR1);
			ft_printf("SIGUSR1\n");
		}
		else
		{
			kill(pid, SIGUSR2);
			ft_printf("SIGUSR2\n");
		}
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("Error: type ./client <PID> <MESSAGE>\n");
		return (0);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		ft_send_bits(pid, argv[2][i]);
		i++;
	}
	//ft_send_bits(pid, '\n');
	return (0);
}
