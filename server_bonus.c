/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:19:17 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/30 11:46:42 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 700
#include "server_bonus.h"

int	ft_kill(int pid, int signum)
{
	if (kill(pid, signum) < 0)
	{
		write(2, "error send\n", 11);
		return (1);
	}
	return (0);
}

//decode the signal, modifying res.
void	handle_signal(int signum, int *i, unsigned char *res)
{
	if (signum == SIGUSR2)
		*res |= 1 << (*i);
	else if (signum == SIGUSR1)
		*res |= 0 << (*i);
	(*i)++;
}

//send to the client SIGUSR1 after
//each received bits or SIGUSR2 if the message is finish.
//print "res" every 8 bits received.
void	print_and_akn(int client_pid, int *i, unsigned char *res)
{
	if (*i == 8)
	{
		if (*res == '\0')
		{
			write(1, "\n", 1);
			ft_kill(client_pid, SIGUSR2); 
			*i = 0;
			return ;
		}
		write(1, res, 1);
		*i = 0;
		*res = 0;
	}
	ft_kill(client_pid, SIGUSR1);
}

//this function is called after each signal, the 2 statics variables
//are used to keep the data intact. it send to the client SIGUSR1 after
//each received bits. and SIGUSR2 if the message is finish
void	sig_handler(int signum, siginfo_t *my_info, void *context )
{
	static int				i;
	static unsigned char	res;
	static int				client_pid;

	client_pid = my_info->si_pid;
	handle_signal(signum, &i, &res);
	print_and_akn(client_pid, &i, &res);
	if (context)
	{
	}
}

int	main(void)
{
	int					server_pid;
	struct sigaction	sa;

	server_pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("server PID : %d\n", server_pid);
	while (1)
	{
	}
	return (0);
}
