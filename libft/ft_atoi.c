/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:02:50 by yalona            #+#    #+#             */
/*   Updated: 2020/03/04 19:25:15 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_res(size_t res, int sign, size_t i)
{
	if (i > 19)
		return (sign == -1 ? 0 : -1);
	if (res > 9223372036854775807)
		return (sign == -1 ? 0 : -1);
	return ((int)res * sign);
}

int			ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	size_t	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '\0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (ft_get_res(res, sign, i));
}
