/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:57:32 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/30 23:29:34 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoint(char *s1, char *s2)
{
	int		i;
	int		l;
	char	*s3;

	i = 0;
	l = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (free(s1), NULL);
	while (s1[i])
	{
		s3[l] = s1[i];
		i++;
		l++;
	}
	i = 0;
	while (s2[i])
		s3[l++] = s2[i++];
	s3[l] = '\0';
	return (free(s1), s3);
}

int	ft_strncmpt(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((s1[i] != '\0') && (i < n)) || ((s2[i] != '\0') && (i < n)))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

char	*send_char(char c, char *str)
{	
	if (!c)
		return (str);
	if (!str)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			exit (0);
		str[0] = c;
		str[1] = '\0';
	}
	else
	{
		str = ft_strjoint(str, &c);
		if (str == NULL)
			exit (0);
	}
	return (str);
}

static void	handle_signal(int signal, siginfo_t *client, void *unused)
{
	static int		m = 1;
	static int		r = 0;
	static int		i = 0;
	char			c = 0; 
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
		c = r;
		str = send_char(c, str);
		if (c == 0)
		{	
			ft_printf("str : %s\n", str);
			if (ft_strncmpt(str, "end", 3) == 0 && ft_strlen(str) == 3)
			{	
				kill(client->si_pid, SIGUSR1);
				free(str);
				str = NULL;
				exit(0);
			}
			free(str);	
			str = NULL;
		}
		i = 0;
		m = 1;
		r = 0;
	}
	kill(client->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	
	if (argc != 1 && argv[0])
		return(ft_printf("Don't put arg\n"), 0);
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