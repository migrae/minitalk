/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:08:55 by mgraefen          #+#    #+#             */
/*   Updated: 2023/01/19 09:23:35 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	send_back_sig(int client_pid)
{
	if (kill(client_pid, SIGUSR2) == -1)
	{
		ft_printf("Error while sending back SIGUSR2 to client");
		return (-1);
	}
	return (0);
}

static void	handle_sig(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bitcount = 0;
	static int	client_pid = 0;

	(void)context;
	if (!client_pid)
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
		if (c == '\0')
			client_pid = send_back_sig(client_pid);
		if (client_pid == -1)
			return ;
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_sig;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("The server is running. Its current process-ID is %d. Use this number with the\
 client to send messages to the server.\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
