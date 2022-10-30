/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:57:32 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/30 19:22:58 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *client)
{
	static int		m = 1;
	static int		r = 0;
	static int		i = 0;
	char			c; 

	if (signal == SIGUSR1)
	{
		r = r + 1 * m;
	}
	else if (signal == SIGUSR2)
	{
		r = r + 0 * m;
	}
	m = m * 2;
	i++;
	if (i == 8)
	{
		c = r;
		ft_printf("%c", c);
		i = 0;
		m = 1;
		r = 0;
	}
	kill(client->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	if (argc != 1)
		return(ft_printf("wrong nb arg\n"), 0);
	ft_printf("PID : %d\n", getpid());

	sig.sa_sigaction = handle_signal;
	sig.sa_flags = SA_SIGINFO;
	while(1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}