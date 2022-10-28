/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:27:19 by mgruson           #+#    #+#             */
/*   Updated: 2022/06/01 21:42:09 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sublen(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s && s[i] && i < start)
		i++;
	while (s && s[i] && j < len)
	{
		i++;
		j++;
	}
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;
	size_t	final_len;

	if (!s)
		return (NULL);
	final_len = ft_sublen(s, start, len);
	dest = (char *)malloc(sizeof(char) * (final_len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < final_len && s[start + i] != '\0')
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main()
{
    char *s;

    s = "mathieu";
    printf("%s\n", ft_substr(s, 2, 2));
    return 0;
}*/
