/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:13:09 by yalona            #+#    #+#             */
/*   Updated: 2019/09/18 13:03:53 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*dest;

	if (size == size + 1)
		return (NULL);
	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(dest, '\0', size + 1);
	return (dest);
}
