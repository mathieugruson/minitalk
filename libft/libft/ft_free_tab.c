/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:18:35 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/28 14:39:28 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab)
{
	int	tablen;
	int	y;

	tablen = ft_tablen(tab);
	y = 0;
	while (y < tablen)
	{
		if (tab[y])
			free(tab[y]);
		y++;
	}	
	if (tab)
		free(tab);
}
