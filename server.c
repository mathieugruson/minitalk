/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:57:32 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/28 23:34:05 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	send_bit(int bit)
// {
// 	static int	base;
// 	static int	i;
// 	static int	letter;

// 	i = 1;
// 	base = 1;
// 	letter = 0;
// 	while (i++ < 8 )
// 	{
// 		letter = letter + bit * base;
// 		base = base * 2;
// 	}
// 	if (i = 8)
// 	{
// 		ft_putchar(letter);
// 		i = 0;
// 		base = 1; 
// 		letter = 0;
// 	}
// }

void	handle_signal(int signal)
{
	// int bit;

	// bit = 0;	
	if (signal == SIGUSR1)
		printf("test 0\n");
		// bit = 0;		
	else if (signal == SIGUSR2)
		printf("test 1\n");	
		// bit = 1;
	// send_bit(bit);
}


int	main(int argc, char **argv)
{
	if (argc != 1)
		return(ft_printf("wrong nb arg\n"), 0);
	ft_printf("PID : %d\n", getpid());
	while(1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
	}
	return (0);
}
