/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 20:33:17 by yalona            #+#    #+#             */
/*   Updated: 2019/09/19 19:31:15 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	int i;
	int len;
	int *p;

	i = 0;
	len = max - min;
	if (min >= max)
		return (0);
	if (!(p = (int*)malloc(sizeof(int) * len)))
		return (0);
	while ((min + i) < max)
	{
		p[i] = min + i;
		i++;
	}
	return (p);
}
