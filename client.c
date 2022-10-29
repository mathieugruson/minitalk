/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:34:13 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/29 17:14:21 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & 1) == 1)
		{
			kill(pid, SIGUSR1);
		}
		if ((c & 1) == 0)
		{
			kill(pid, SIGUSR2);			
		}
		c = c >> 1;
		usleep(200);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int i;
	int	strlen;
	// securiser avec les arguments
	pid = ft_atoi(argv[1]); 
	i = 0;
	strlen = ft_strlen(argv[2]);
	while(i < strlen)
	{	
		send_message(pid, argv[2][i]);
		i++;
	}
	return (0);
}
