/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:04:10 by mafranco          #+#    #+#             */
/*   Updated: 2023/10/09 22:53:41 by mafranco         ###   ########.fr       */
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

void	send_bits(int pid, char i)
{
	int		bit;
	char	*bits;

	bits = getbits(i);
	bit = 7;
	while (bit >= 0)
	{
		if (bits[bit] == 49)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(75);
		bit--;
	}
	free(bits);
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
		send_bits(pid, argv[2][i]);
		i++;
	}
	send_bits(pid, '\n');
	return (0);
}
