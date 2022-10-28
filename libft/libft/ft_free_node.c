/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:49:35 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/16 13:19:43 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_free_node(t_list *node)
{
	t_list	*tmp;

	tmp = node;
	if (node->next != NULL)
	{
		node = node->next;
		free(tmp);
		return (node);
	}
	if (node->next == NULL)
	{
		free(node);
		return (NULL);
	}
	return (node);
}
