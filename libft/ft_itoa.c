/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:41:37 by yalona            #+#    #+#             */
/*   Updated: 2019/09/18 18:22:40 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_res(char *dest, int sign, int i, int n)
{
	dest[i] = '\0';
	while (i >= 1)
	{
		dest[i - 1] = (n % 10) * sign + '0';
		n = n / 10;
		i = i - 1;
	}
	if (sign == -1)
	{
		dest[i] = '-';
	}
}

char		*ft_itoa(int n)
{
	char	*dest;
	int		i;
	int		a;
	int		sign;

	i = 1;
	a = n;
	sign = 1;
	if (n < 0)
	{
		i = i + 1;
		sign = -1;
	}
	while (a / 10 >= 1 || a / 10 <= -1)
	{
		i++;
		a = a / 10;
	}
	if (!(dest = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_res(dest, sign, i, n);
	return (dest);
}
