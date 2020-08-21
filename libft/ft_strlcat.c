/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:49:38 by yalona            #+#    #+#             */
/*   Updated: 2019/09/19 18:53:51 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t ret;

	i = 0;
	ret = 0;
	while (dst[i])
		i = i + 1;
	while (src[ret])
		ret = ret + 1;
	if (size <= i)
		ret = ret + size;
	else
		ret = ret + i;
	j = 0;
	while (src[j] && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ret);
}
