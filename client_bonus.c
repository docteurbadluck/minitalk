/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:14:01 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/30 11:35:37 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"
#define _BSD_SOURCE

volatile sig_atomic_t	g_busy = 1;

int	bit_bangin_return(unsigned char c, int bit)
{
	unsigned char	result;

	result = 0;
	result = (c >> bit & 1);
	return (result);
}

//we wait that the server modify g_busy to declare that the message is received.
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

//we use this time the same code but with a global variable
//that allow us to wait until the server send a signal back.
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
			if (bit_bangin_return(str[i], bit))
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

//we use the struct sigaction to handle signal. 
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
		write(2, "error\n usage :<pid server> <message>\n", 37);
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
