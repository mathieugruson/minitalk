/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:50:17 by mgruson           #+#    #+#             */
/*   Updated: 2022/06/01 21:21:36 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long long nbr)
{
	long long int	len;

	len = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	long long int	n_long;

	n_long = n;
	len = num_len(n_long);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n_long < 0)
	{
		str[0] = '-';
		n_long = n_long * -1;
	}
	while (n_long >= 0)
	{
		len--;
		str[len] = n_long % 10 + '0';
		n_long = n_long / 10;
		if (n_long == 0)
			n_long = -1;
	}
	return (str);
}

// int    main(void)
// {
//     printf("%s \n", ft_itoa(0));
//     printf("%s \n", ft_itoa(-12590));
//     printf("%s \n", ft_itoa(4));
//     printf("%s \n", ft_itoa(-1));
//     printf("%s \n", ft_itoa(INT_MIN));
//     printf("%s \n", ft_itoa(INT_MAX));
//     printf("%s \n", ft_itoa(12590));

//     return (0);
// }