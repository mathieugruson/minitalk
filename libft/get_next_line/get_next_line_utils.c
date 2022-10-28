/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:43:51 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/17 13:34:03 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	int		l;
	char	*s3;
	int		len_s1;
	int		len_s2;

	len_s1 = ft_strlen_gnl(s1);
	len_s2 = ft_strlen_gnl(s2);
	i = 0;
	l = 0;
	if ((!s1 && !s2) || len_s1 + len_s2 == 0)
		return (free(s1), NULL);
	s3 = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!s3)
		return (free(s1), NULL);
	while (s1 && s1[i])
		s3[l++] = s1[i++];
	s3[l] = '\0';
	i = 0;
	while (s2 && s2[i])
		s3[l++] = s2[i++];
	s3[l] = '\0';
	return (free(s1), s3);
}

int	ft_memchr_gnl(char *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || !s)
		return (0);
	while (i < n && s[i])
	{
		if (((char unsigned *)s)[i] == (unsigned char)c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
