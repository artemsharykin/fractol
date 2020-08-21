/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:49:38 by yalona            #+#    #+#             */
/*   Updated: 2019/09/17 21:48:49 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_div(int n, int fd)
{
	if (n < 10 && n > -10)
	{
		if (n < 0)
			ft_putchar_fd((-1 * n + '0'), fd);
		else
			ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_div(n / 10, fd);
		ft_div(n % 10, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		ft_div(n, fd);
	else
	{
		ft_putchar_fd('-', fd);
		ft_div(n, fd);
	}
}
