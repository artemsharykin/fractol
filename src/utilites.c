/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:16:48 by yalona            #+#    #+#             */
/*   Updated: 2020/08/22 17:41:58 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int	exiterror(void)
{
	ft_putstr_fd("error\n", 1);
	exit(-1);
}

int	exit_cl(void)
{
	exit(0);
}

int	error(void)
{
	ft_putstr_fd("error\n", 1);
	return (-1);
}

int	usage(void)
{
	ft_putstr_fd("available fractals: ./fractol [julia]	[mandelbrot]\
	[burningship]\n", 2);
	return (-1);
}
