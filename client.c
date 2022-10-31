/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:34:13 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/31 12:18:32 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_receive;

void	handle_server_signal(int signal)
{
	(void)signal;
	g_receive = 1;
}

void	send_message(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_receive = 0;
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
		while (!g_receive)
		{
			pause();
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	strlen;

	if (argc != 3)
		return (ft_printf("Wrong args\n"), 0);
	pid = ft_atoi(argv[1]);
	if (pid < 1 || pid > 4194304)
		ft_printf("Invalid pid\n");
	i = 0;
	strlen = ft_strlen(argv[2]);
	signal(SIGUSR1, handle_server_signal);
	while (i <= strlen)
	{
		send_message(pid, argv[2][i]);
		i++;
	}
	return (0);
}
