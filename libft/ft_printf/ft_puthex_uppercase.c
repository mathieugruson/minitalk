/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:26:26 by mgruson           #+#    #+#             */
/*   Updated: 2022/06/27 13:04:41 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_uppercase(unsigned int n)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_puthex_uppercase(n / 16);
		ft_puthex_uppercase(n % 16);
	}
	if (n < 16)
		ft_putchar(base[n]);
}
