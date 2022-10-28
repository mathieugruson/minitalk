/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:09:22 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/28 12:40:39 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>

# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_nbrlen(long long n);
int		ft_unslen(unsigned int n);
int		ft_hexlen(unsigned long long n);
int		ft_putnbr(int nb);
void	ft_putuns(unsigned int nb);
void	ft_putptr(unsigned long long n);
void	ft_puthex_lowercase(unsigned int n);
void	ft_puthex_uppercase(unsigned int n);
int		ft_s_conversion(va_list args);
int		ft_c_conversion(va_list args);
int		ft_d_conversion(va_list args);
int		ft_p_conversion(va_list args);
int		ft_x_conversion(va_list args);
int		ft_xupper_conversion(va_list args);
int		ft_u_conversion(va_list args);

#endif 