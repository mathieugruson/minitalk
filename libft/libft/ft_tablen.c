/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:25:10 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/18 11:52:33 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tablen(char **tab)
{	
	int	y;

	y = 0;
	while (tab[y])
	{
		y++;
	}
	return (y);
}

/*
This function returns the line number of a table
As tab[0] is the irst line of a table, y is the last line but not
the protection
*/