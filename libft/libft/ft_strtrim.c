/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:18:27 by mgruson           #+#    #+#             */
/*   Updated: 2022/06/01 21:41:19 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_check(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_trimlen(char const *s1, char const *set)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (s1[i] && ft_set_check(set, s1[i]))
	{
		l++;
		i++;
	}
	i = ft_strlen(s1) - 1;
	while (s1[i] && ft_set_check(set, s1[i]))
	{
		l++;
		i--;
	}
	return (l);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*s2;

	i = 0;
	j = 0;
	len = ft_strlen(s1) - ft_trimlen(s1, set);
	if (len < 0)
		len = 0;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (s1 && ft_set_check(set, s1[i]))
		i++;
	while (j < len)
	{
		s2[j] = s1[i];
		j++;
		i++;
	}
	s2[j] = '\0';
	return (s2);
}
/*
int main(void)
{
    //printf("the final result id =>%s", ft_strtrim("xyxmathxieuyxy", "xy"));
    char    *strtrim;


        char s1[] = "lorem ipsum dolor sit amet";
        if (!(strtrim = ft_strtrim(s1, "te")))
            printf("NULL");
        else
            printf("%s",ft_strtrim(s1, "te"));
        if (ft_strtrim(s1, " ") == s1)
            printf("\nA new string was not returned");
}*/