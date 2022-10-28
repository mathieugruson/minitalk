/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:33:52 by mgruson           #+#    #+#             */
/*   Updated: 2022/06/27 13:04:41 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_lowercase(unsigned int n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthex_lowercase(n / 16);
		ft_puthex_lowercase(n % 16);
	}
	if (n < 16)
		ft_putchar(base[n]);
}
