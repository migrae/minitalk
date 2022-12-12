/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:08:55 by mgraefen          #+#    #+#             */
/*   Updated: 2022/12/12 15:20:45 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_sig(int sig, siginfo_t *info, void *context)
{
	(void)context;
	static char	c = 0;
	static int	bitcount = 0;
	static int	client_pid = 0;
	
	if(!client_pid)
		client_pid = info->si_pid;
	if (bitcount < 16)
	{
		if (sig == SIGUSR2)
			c += 1 << bitcount;
		bitcount++;
	}
	if (bitcount == 16)
	{
		bitcount = 0;
		if(c == '\0')
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}	
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	struct sigaction sa;
	sa.sa_sigaction = &handle_sig;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("The server is running. Its current process-ID is %d. Use this number with the\
 client to send messages to the server.\n", getpid());

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}	
	return (0);
}
