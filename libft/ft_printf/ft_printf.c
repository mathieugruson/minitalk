/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:27:04 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/16 19:13:14 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_selector(va_list args, const char *str_arg, int i)
{
	unsigned int	len;

	len = 0;
	i++;
	if (str_arg[i] == 's')
		len = ft_s_conversion(args);
	if (str_arg[i] == 'c')
		len = ft_c_conversion(args);
	if (str_arg[i] == 'p')
		len = ft_p_conversion(args);
	if (str_arg[i] == 'd' || str_arg[i] == 'i')
		len = ft_d_conversion(args);
	if (str_arg[i] == 'u')
		len = ft_u_conversion(args);
	if (str_arg[i] == 'x')
		len = ft_x_conversion(args);
	if (str_arg[i] == 'X')
		len = ft_xupper_conversion(args);
	if (str_arg[i] == '%')
	{
		ft_putchar('%');
		len++;
	}
	return (len);
}

int	ft_printf(const char *first_arg, ...)
{
	va_list		args;
	int			i;
	const char	*str_arg;
	int			len;

	va_start(args, first_arg);
	i = 0;
	len = 0;
	str_arg = first_arg;
	while (str_arg[i])
	{
		if (str_arg[i] == '%')
		{
			len = len + ft_conversion_selector(args, str_arg, i);
			i = i + 2;
		}
		if (str_arg[i] && str_arg[i] != '%')
		{
			write(1, &str_arg[i], 1);
			i++;
			len++;
		}
	}
	va_end (args);
	return (len);
}
