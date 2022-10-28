/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:23:27 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/18 15:52:31 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabcpy(char **tab)
{
	int		i;
	int		tablen;
	char	**cpy;

	tablen = ft_tablen(tab);
	i = 0;
	cpy = malloc(sizeof(char *) * (tablen + 1));
	if (!cpy)
		return (NULL);
	cpy[tablen] = NULL;
	while (i < tablen)
	{
		cpy[i] = malloc(sizeof(char) * (ft_strlen(tab[i]) + 1));
		if (!cpy[i])
			return (NULL);
		ft_strlcpy(cpy[i], tab[i], (ft_strlen(tab[i]) + 1));
		i++;
	}
	return (cpy);
}

/* 
This function makes a copy of a tab, including protection.
Be careful, the table copied must be protected if
we want this function running smoothly
*/