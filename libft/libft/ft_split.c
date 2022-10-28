/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:44:14 by mgruson           #+#    #+#             */
/*   Updated: 2022/05/17 12:48:19 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tab(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			count++;
			i++;
		}
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static char	**ft_free(char **s, int t)
{
	while (t >= 0)
	{
		free(s[t]);
		s[t] = NULL;
		t--;
	}
	return (s);
}

static char	**ft_taboftab(char const *s, char c, char **s1)
{
	int	i;
	int	count;
	int	t;

	i = 0;
	count = 0;
	t = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i++] != c)
			count++;
		if (count != 0)
		{
			s1[t] = (char *)ft_calloc((count + 1), sizeof(char));
			if (!s1[t++])
			{
				s1 = ft_free(s1, t);
				return (s1);
			}
		}
		count = 0;
	}
	return (s1);
}

static char	**ft_fill(char const *s, char c, char **s1)
{
	int	l;
	int	i;
	int	t;

	l = 0;
	i = 0;
	t = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			s1[t][l++] = s[i++];
		if (s1[t])
			s1[t++][l] = '\0';
		l = 0;
	}
	s1[t] = NULL;
	return (s1);
}

char	**ft_split(char const *s, char c)
{
	char	**s1;

	if (!s)
		return (NULL);
	s1 = (char **)ft_calloc((ft_tab(s, c) + 1), sizeof(char *));
	if (!s1)
		return (NULL);
	s1 = ft_taboftab(s, c, s1);
	if (!*s1)
	{
		return (s1);
	}
	s1 = ft_fill(s, c, s1);
	return (s1);
}

// int main()
// {
// 	char	**tabstr;
// 	int		i;

// 	i = 0;
// 	if (!(tabstr = ft_split("lorem ipsnon risus. Suspendisse", ' ')))
// 		printf("NULL\n");
// 	else
// 	{
// 		while (tabstr[i])
// 		{
// 			printf("%s\n", tabstr[i]);
// 			free(tabstr[i]);		
// 			write(1, "\n", 1);
// 			i++;
// 		}
// 	}
// 	free (tabstr);
// }