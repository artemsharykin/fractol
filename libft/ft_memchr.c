/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:53:59 by yalona            #+#    #+#             */
/*   Updated: 2019/09/19 18:46:00 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*dst;

	dst = s;
	while (n--)
	{
		if (*dst == (unsigned char)c)
		{
			return ((void*)dst);
		}
		dst++;
	}
	return (0);
}
