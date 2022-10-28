/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:30:35 by mathieug          #+#    #+#             */
/*   Updated: 2022/05/25 16:11:19 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_string;
	int		i;

	i = 0;
	new_string = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_string)
		return (0);
	while (s[i])
	{
		new_string[i] = s[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
/*
int main()
{
    char *p;

    p = "mathieu";
    ft_strdup(p);
    return 0;


}*/