/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:05:23 by yalona            #+#    #+#             */
/*   Updated: 2019/09/18 19:05:25 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t num)
{
	size_t			i;
	unsigned char	*p_dest;
	unsigned char	*p_src;

	if (dest == 0 && src == 0)
		return ((void *)dest);
	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	i = 0;
	while (i < num)
	{
		p_dest[i] = p_src[i];
		if (p_dest[i] == (unsigned char)c)
			return (((void *)dest) + (i + 1));
		i++;
	}
	return (0);
}
