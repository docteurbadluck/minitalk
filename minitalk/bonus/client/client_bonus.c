/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:14:01 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/16 17:30:48 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"
#define _BSD_SOURCE

volatile sig_atomic_t	g_busy = 1;

int	big_bangin_return(unsigned char c, int bit)
{
	unsigned char	result;

	result = 0;
	result = (c >> bit & 1);
	return (result);
}

void	end_management(int pid_server)
{
	int	bit;

	bit = -1;
	while (++bit <= 7)
	{
		kill(pid_server, SIGUSR1);
		usleep(10);
	}
	if (g_busy == 2)
	{
		write(1, "OK!", 3);
	}
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
			g_busy = 1;
			if (big_bangin_return(str[i], bit))
				kill(pid_server, SIGUSR2);
			else
				kill(pid_server, SIGUSR1);
			bit++;
			while (g_busy)
				usleep(1);
		}
		bit = 0;
		i++;
	}
	end_management(pid_server);
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_busy = 0;
	}
	if (signum == SIGUSR2)
	{
		g_busy = 2;
	}
}

int	main(int argc, char **argv)
{
	int					pid_server;
	char				*str;
	struct sigaction	sa_client;

	sa_client.sa_handler = handler;
	sa_client.sa_flags = 0;
	sigemptyset(&sa_client.sa_mask);
	sigaddset(&sa_client.sa_mask, SIGUSR1);
	sigaddset(&sa_client.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa_client, NULL);
	sigaction(SIGUSR2, &sa_client, NULL);
	if (argc != 3)
	{
		write(2, "error\n", 6);
		exit(1);
	}
	else
	{
		pid_server = ft_atoi(argv[1]);
		str = argv[2];
		ft_send_str(str, pid_server);
	}
	return (0);
}
