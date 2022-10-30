/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:34:13 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/30 22:52:39 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		receive;

void	handle_signal(int signal)
{
	(void)signal;
	receive = 1;
}

void	send_message(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		receive = 0;
		if ((c & 1) == 1)
		{
			kill(pid, SIGUSR1);
		}
		if ((c & 1) == 0)
		{
			kill(pid, SIGUSR2);			
		}
		c = c >> 1;
		i++;
		while (!receive)
		{
			pause();
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int i;
	int	strlen;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid < 1 || pid > 4194304)
		write(2, "Invalid arguments\n", 18); 
	i = 0;
	strlen = ft_strlen(argv[2]);

	signal(SIGUSR1, handle_signal);
	while(i <= strlen)
	{
		send_message(pid, argv[2][i]);
		i++;	
	}
	return (0);
}
