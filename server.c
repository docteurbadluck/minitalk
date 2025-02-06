/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:19:17 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/05 10:48:52 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 700
#include "server.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//attribute bit wise 1 or 0 depending of wich signal is receive until a char
//is complete, then it print it.
void	handler(int signum)
{
	static int				i;
	static unsigned char	res;

	if (signum == SIGUSR2)
		res |= 1 << i;
	else if (signum == SIGUSR1)
		res |= 0 << i;
	i++;
	if (i == 8)
	{
		if (res == '\0')
		{
			write(1, "\n", 1);
			i = 0;
			return ;
		}
		write(1, &res, 1);
		i = 0;
		res = 0;
	}
}

//sigaction struct allow us to use a newer version of the function 'signal()'
//the code work but it is quit fragil in case of interuption from client
int	main(void)
{
	int					server_pid;
	struct sigaction	sa;

	server_pid = getpid();
	sa.sa_flags = 0; 
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("server PID : %d\n", server_pid);
	while (1)
	{
	}
	return (0);
}
