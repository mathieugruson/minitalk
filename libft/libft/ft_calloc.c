/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:36:52 by mathieug          #+#    #+#             */
/*   Updated: 2022/05/25 16:52:54 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*tab;

	if (nmeb && ((nmeb * size / nmeb) != size))
		return (NULL);
	tab = malloc(nmeb * size);
	if (!tab)
		return (NULL);
	ft_bzero((char *)tab, size * nmeb);
	return ((char *)tab);
}
