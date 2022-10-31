/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:57:32 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/31 12:34:31 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*send_char(int r, char *str)
{	
	char	*tmp;

	if (r == 0)
		return (str);
	tmp = malloc(sizeof(char) * 2);
	if (!tmp)
		return (NULL);
	tmp[0] = r;
	tmp[1] = '\0';
	if (!str)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (free(str), NULL);
		str[0] = r;
		str[1] = '\0';
	}
	else
	{
		str = ft_strjoin(str, tmp);
		if (str == NULL)
			return (NULL);
	}
	return (free(tmp), str);
}

char	*display_message(int r, char *str, siginfo_t *client)
{
	if (str == 0)
	{
		ft_printf("Malloc error\n");
		exit (0);
	}
	if (r == 0)
	{	
		ft_printf("%s\n", str);
		if (ft_strncmp(str, "end", 3) == 0 && ft_strlen(str) == 3)
		{	
			kill(client->si_pid, SIGUSR1);
			free(str);
			str = NULL;
			exit(0);
		}
		free(str);
		str = NULL;
	}
	return (str);
}

void	handle_client_signal(int signal, siginfo_t *client, void *unused)
{
	static int		m = 1;
	static int		r = 0;
	static int		i = 0;
	static char		*str = NULL;

	(void)unused;
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
		str = send_char(r, str);
		str = display_message(r, str, client);
		i = 0;
		m = 1;
		r = 0;
	}
	kill(client->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sact;
	sigset_t			sigset;

	if (argc != 1 && argv[0])
		return (ft_printf("Don't put arg\n"), 0);
	ft_printf("PID : %d\n", getpid());
	sigemptyset(&sact.sa_mask);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	sact.sa_sigaction = handle_client_signal;
	sact.sa_flags = SA_SIGINFO;
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	while (1)
	{
		sigaction(SIGUSR1, &sact, NULL);
		sigaction(SIGUSR2, &sact, NULL);
		pause();
	}
	return (0);
}
