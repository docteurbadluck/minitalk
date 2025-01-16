/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:14:01 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/16 12:46:59 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#define _BSD_SOURCE

int	big_bangin_return(unsigned char c, int bit)
{
	unsigned char	result;

	result = 0;
	result = (c >> bit & 1);
	return (result);
}

int	ft_kill(int pid, int signum)
{
	if (kill(pid, signum) < 0)
	{
		write(2, "error send\n", 11);
		return (1);
	}
	return (0);
}

void	ft_send_str(char *str, int pid_server)
{
	int	bit;
	int	i;

	i = 0;
	bit = 0;
	while (str[i])
	{
		while (bit <= 7)
		{
			if (big_bangin_return(str[i], bit))
				ft_kill(pid_server, SIGUSR2);
			else
				ft_kill(pid_server, SIGUSR1);
			usleep(10);
			bit++;
		}
		bit = 0;
		i++;
	}
	bit = -1;
	while (++bit <= 7)
	{
		kill(pid_server, SIGUSR1);
		usleep(10);
	}
}

int	main(int argc, char **argv)
{
	int		pid_server;
	char	*str;

	if (argc != 3)
	{
		write(2, "error\n", 6);
		return (1);
	}
	else
	{
		pid_server = ft_atoi(argv[1]);
		str = argv[2];
		ft_send_str(str, pid_server);
	}
	return (0);
}
