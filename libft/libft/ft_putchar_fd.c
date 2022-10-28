/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:40:38 by mgruson           #+#    #+#             */
/*   Updated: 2022/06/01 21:27:36 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

/*
int main ()
{
    char let;
    char *letter ;
    
    letter = &let;
    let = 'M'; 
    ft_putchar_fd(let, 1); // marche aussi avec pointeur *letter;
    return(0);
}*/
