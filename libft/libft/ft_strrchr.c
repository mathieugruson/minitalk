/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:30:22 by mgruson           #+#    #+#             */
/*   Updated: 2022/05/23 18:37:59 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	l;

	l = ft_strlen((char *)s);
	while (l != 0)
	{
		if (s[l] == (char)c)
			return ((char *)s + l);
		l--;
	}
	if (s[l] == (char)c)
		return ((char *)s + l);
	return (NULL);
}
/*
int main ()
{
    char *str;

    str = "helleo";
    printf("%s\n", ft_strchr(str, 'l'));
    printf("%s\n", strrchr(str, 'l'));
}*/