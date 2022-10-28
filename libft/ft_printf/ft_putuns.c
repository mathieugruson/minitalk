/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:58:41 by mgruson           #+#    #+#             */
/*   Updated: 2022/06/27 13:04:41 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuns(unsigned int nb)
{
	static int	len;

	if (!len)
		len = 0;
	if (nb > 9)
	{
		ft_putuns(nb / 10);
		ft_putuns(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}
