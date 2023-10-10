/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:04:10 by mafranco          #+#    #+#             */
/*   Updated: 2023/10/10 17:41:38 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char	*getbits(int c)
{
	char	*bits;
	int		i;
	int		nb;

	bits = (char *)malloc(sizeof(char) * 9);
	if (!bits)
		return (NULL);
	i = 1;
	nb = 128;
	while (i <= 8)
	{
		if (c / nb == 1)
		{
			bits[i - 1] = 49;
			c -= nb;
		}
		else
			bits[i - 1] = 48;
		i++;
		nb /= 2;
	}
	bits[i - 1] = '\0';
	return (bits);
}

int	send_bits(int pid, char i)
{
	int		bit;
	char	*bits;

	bits = getbits(i);
	if (!bits)
		return (1);
	bit = 7;
	while (bit >= 0)
	{
		if (bits[bit] == 49)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		bit--;
	}
	free(bits);
	return (0);
}

void	checkpid(int pid)
{
	if (pid <= 0)
	{
		ft_printf("Pid must be > 0\n");
		exit(EXIT_FAILURE);
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
	checkpid(pid);
	while (argv[2][i] != '\0')
	{
		if (send_bits(pid, argv[2][i]) == 1)
		{
			ft_printf("Allocating memory failed\n");
			return (0);
		}
		i++;
	}
	send_bits(pid, '\n');
	return (0);
}
