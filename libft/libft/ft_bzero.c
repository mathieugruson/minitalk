/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:17:27 by mgruson           #+#    #+#             */
/*   Updated: 2022/05/23 17:24:16 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		*(char *)s++ = '\0';
		i++;
	}
	return ((char *)s);
}

/*
int main()
{
    char tab[10] =  "mathieu";
    char tab1[10] =  "oscar";
    size_t n;

    n = 1;
    bzero(tab, n);
    printf("%s\n", tab);
    ft_bzero(tab1, n);
    printf("%s\n", tab1);

    return (0);
}*/