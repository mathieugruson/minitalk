/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:57:32 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/29 17:52:35 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, char *tab)
{
	static int		m = 1;
	static int		r = 0;
	static int		i = 0;
	char			c; 

	if (signal == SIGUSR1)
	{
		r = r + 1 * m;
		// printf("bit 1\n");
	}
	else if (signal == SIGUSR2)
	{
		r = r + 0 * m;
		// printf("bit 0\n");	
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

}

int	main(int argc, char **argv)
{

	tab = malloc(sizeof(char))
	if (argc != 1)
		return(ft_printf("wrong nb arg\n"), 0);
	ft_printf("PID : %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while(1)
	{
		pause();
	}
	return (0);
}

// int	main()
// {
// 	int a = 0;
// 	int i = 0;
// 	char b;
// 	char *c = "taf";
// 	int	r = 0;
// 	int	m = 1;
// 	char *str;
// 	str = malloc(sizeof(char) * (3 + 1));
// 	str[3] = '\0';
// 	while(a < 3)
// 	{	
// 		i = 0;
// 		r = 0;
// 		m = 1;
// 		b = c[a];
// 		while (i < 8)
// 		{
// 			if ((b & 1) == 1)
// 				r = r + 1 * m; 
// 			else
// 				r = r + 0 * m;
// 			i++;
// 			b = b >> 1;
// 			m = m * 2;
// 		}
// 		str[a] = r;
// 		a++;
// 	}
// 	printf("str : %s\n", str);
// }