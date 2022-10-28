/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_c_d_p_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:22:38 by mgruson           #+#    #+#             */
/*   Updated: 2022/06/27 13:04:41 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s_conversion(va_list args)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(args, char *);
	if (!str)
		return (write(1, "(null)", 6));
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (ft_strlen(str));
}

int	ft_c_conversion(va_list args)
{
	const char	*c;

	c = va_arg(args, const char *);
	write(1, &c, 1);
	return (1);
}

int	ft_d_conversion(va_list args)
{
	int	d;

	d = va_arg(args, int);
	ft_putnbr(d);
	return (ft_nbrlen(d));
}

int	ft_p_conversion(va_list args)
{
	unsigned long long	p;

	p = va_arg(args, unsigned long long);
	if (p == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	ft_putptr(p);
	return (ft_hexlen(p) + 2);
}
