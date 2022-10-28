/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_xupper_u_conversion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:55:24 by mgruson           #+#    #+#             */
/*   Updated: 2022/06/27 13:04:41 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x_conversion(va_list args)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	ft_puthex_lowercase(x);
	return (ft_hexlen(x));
}

int	ft_xupper_conversion(va_list args)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	ft_puthex_uppercase(x);
	return (ft_hexlen(x));
}

int	ft_u_conversion(va_list args)
{
	unsigned int	u;

	u = va_arg(args, unsigned int);
	ft_putuns(u);
	return (ft_unslen(u));
}
