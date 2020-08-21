/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:03:21 by yalona            #+#    #+#             */
/*   Updated: 2019/09/15 15:28:42 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(dest) * size)))
		return (NULL);
	while (i < size)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
