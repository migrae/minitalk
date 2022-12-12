/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:08:52 by mgraefen          #+#    #+#             */
/*   Updated: 2022/12/12 15:24:27 by mgraefen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_pid(char *pid)
{
	int i;

	i = 0;
	if (!pid)
		return (ft_printf("Error in check_pid"), 1);
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (0);
		i++;
	}
	return(1);
}

void ft_received(int sig)
{
	(void)sig;
	ft_printf("The server received the given message");
}

int	send_input(int pid, char c)
{
	int i;

	i = 0;
	if (!pid)
		return (ft_printf("Error in send_input"), 1);
	while (i < 16)
	{
		if (!(c & 1))
		{
			kill(pid, SIGUSR1);
			c >>= 1;
		}
		else
		{
			kill(pid, SIGUSR2);
			c >>= 1;
		}
		usleep(50);
		i++;
	}
	i = 0;
	return (0);
}

int	prep_input(int pid, char* input)
{
	size_t i;

	i = 0;
	if (!pid || !input)
		return (ft_printf("Error in prep_input"), 1);
	while (input[i])
	{
		send_input(pid, input[i]);
		i++;
	}
	send_input(pid, input[i]);
	return (0);
}

int main(int argc, char* argv[])
{
	int pid;

	if (argc != 3)
	{
		ft_printf("Only 2 arguments are allowed. The process-ID & the message you want to send.\n");
		return (1);
	}
	if(!check_pid(argv[1]))
	{
		ft_printf("Only use numbers for the process-ID, please!\n");
		return (1);
	}
	if (kill(ft_atoi(argv[1]), 0) == -1)
	{
		ft_printf("This process-ID does not excist. Please check the message given by the server");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR2, &ft_received);
	prep_input(pid, argv[2]);	
	return (0);
}
