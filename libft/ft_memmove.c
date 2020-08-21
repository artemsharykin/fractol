/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:59:36 by yalona            #+#    #+#             */
/*   Updated: 2019/09/19 18:45:25 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*sourc;

	dest = (unsigned char *)dst;
	sourc = (unsigned char *)src;
	if (sourc == dest)
		return (dst);
	if (sourc < dest)
	{
		sourc = sourc + len - 1;
		dest = dest + len - 1;
		while (len--)
		{
			*dest = *sourc;
			dest = dest - 1;
			sourc = sourc - 1;
		}
	}
	else
		ft_memcpy(dest, sourc, len);
	return (dst);
}
