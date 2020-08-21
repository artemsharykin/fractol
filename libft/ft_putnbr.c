/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:16:19 by yalona            #+#    #+#             */
/*   Updated: 2019/09/17 21:47:59 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_div(int n)
{
	if (n < 10 && n > -10)
	{
		if (n < 0)
			ft_putchar(-1 * n + '0');
		else
			ft_putchar(n + '0');
	}
	else
	{
		ft_div(n / 10);
		ft_div(n % 10);
	}
}

void		ft_putnbr(int n)
{
	if (n >= 0)
		ft_div(n);
	else
	{
		ft_putchar('-');
		ft_div(n);
	}
}
