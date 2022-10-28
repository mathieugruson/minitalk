/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:38:40 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/17 15:20:29 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list *lst)
{
	if (lst == NULL)
		return ;
	while (lst)
	{
		ft_putnode(lst);
		lst = lst->next;
	}
}
