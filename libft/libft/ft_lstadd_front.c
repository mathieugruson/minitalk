/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:13:50 by mathieug          #+#    #+#             */
/*   Updated: 2022/05/31 12:25:06 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	(*new).next = *lst;
	*lst = new;
}

// int    ft_lstsize(t_list *lst)
// {
//     int i;

//     i = 0;
//     while(lst)
//     {
//         printf("%s\n", (char *)(*lst).content);
// 		lst = (*lst).next;
//         i++;
//     }
//    return (i);
// }

// t_list *add_link(t_list *list, char *content)
// {
//     t_list  *tmp;

//     tmp = malloc(sizeof(t_list));
//     if (tmp)
//     {
//         (*tmp).content = content; 
//         (*tmp).next = list; 
//     }
//     return (tmp);
// }

// int main()
// {
//     t_list  *lst;
// 	t_list	*new;

//     lst = NULL;
// 	new = NULL;
//     lst = add_link(lst, "tot");
//     new = add_link(new, "tat");
//     lst = add_link(lst, "tut");
// 	ft_lstadd_front(&lst, new);
//     printf("%d\n", ft_lstsize(lst));

//     return (0);
// }