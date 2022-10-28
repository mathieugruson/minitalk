/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:50:53 by mgruson           #+#    #+#             */
/*   Updated: 2022/05/23 17:47:20 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src > dst)
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n)
		{
			n--;
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
		}
	}
	return (dst);
}

/*
int main()
{
    char    src[] = "mathieugruson";
    char    *dest;

    dest = &src[3];

    char    src1[] = "mathieugruson";
    char    *dest1;

    dest1 = &src1[3];

    char    src2[] = "mathieugruson";
    char    *dest2;

    dest2 = &src2[3];
    
    printf("Before dest = %s, src = %s\n", dest1, src1);
    ft_memmove(dest1, src1, 6);
    printf("After dest = %s, src = %s\n", dest1, src1);

    printf("Before dest = %s, src = %s\n", dest2, src2);
    memcpy(dest2, src2, 6);
    printf("After dest = %s, src = %s\n", dest2, src2);

    return (0);
}*/