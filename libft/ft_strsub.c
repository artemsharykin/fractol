/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:16:08 by yalona            #+#    #+#             */
/*   Updated: 2019/09/18 11:15:55 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (*s && len)
	{
		dest[i] = s[start];
		start++;
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
