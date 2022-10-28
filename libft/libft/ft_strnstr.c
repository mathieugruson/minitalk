/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:41:54 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/17 10:46:48 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int len)
{
	int	i;
	int	j;
	int	save;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)(big));
	while (((big[i] != '\0') && (little[j] != '\0')) && (i < len))
	{
		save = i;
		while (big[i] == little[j] && (i < len))
		{
			i++;
			j++;
			if (j == ft_strlen(little))
				return ((char *)(&(big[i - j])));
		}
		j = 0;
		i = save + 1;
	}
	return (NULL);
}

/*
int main()
{
    const char *largestring = "Foo Bar Baz";
    const char *smallstring = "Foo";
    
    printf("%s\n", ft_strnstr(largestring, smallstring, 3));
    return 0;
}*/