/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:08:07 by mgruson           #+#    #+#             */
/*   Updated: 2022/06/27 13:04:41 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putptr(n / 16);
		ft_putptr(n % 16);
	}
	if (n < 16)
		ft_putchar(base[n]);
}
