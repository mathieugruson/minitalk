/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:06:30 by mgruson           #+#    #+#             */
/*   Updated: 2022/06/02 12:03:38 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return ((char *)dest);
}

// int main()
// {
//     char    src[] = "mathieugruson";
//     char    *dest;

//     dest = &src[3];

//     char    src1[] = "mathieugruson";
//     char    *dest1;

//     dest1 = &src1[3];

//     char    src2[] = "mathieugruson";
//     char    *dest2;

//     dest2 = &src2[3];
//     printf("Before dest = %s, src = %s\n", dest, src);
//     ft_memcpy(dest, src, 6);
//     printf("After dest = %s, src = %s\n", dest, src);

//     printf("Before dest = %s, src = %s\n", dest1, src1);
//     ft_memmove(dest1, src1, 6);
//     printf("After dest = %s, src = %s\n", dest1, src1);

//     printf("Before dest = %s, src = %s\n", dest2, src2);
//     memcpy(dest2, src2, 6);
//     printf("After dest = %s, src = %s\n", dest2, src2);

//     return (0);
// }