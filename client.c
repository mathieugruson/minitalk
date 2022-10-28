/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:34:13 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/28 23:35:28 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid)
{
	int	bit;
	
	bit = 0;
	while (bit++ < 8)
	{
		if (bit % 2 == 1)
			kill(pid, SIGUSR2);
		if (bit % 2 == 0)
			kill(pid, SIGUSR2);
		printf("c1\n");
	}  
}

int	main(int argc, char **argv)
{
	int	pid;
	// securiser avec les arguments
	pid = ft_atoi(argv[1]); 
	send_message(pid);
	return (0);
}

/*
kill = send signal and the process which receive it know what to do with it

*/
