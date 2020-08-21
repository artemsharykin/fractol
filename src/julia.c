/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 15:59:05 by yalona            #+#    #+#             */
/*   Updated: 2020/08/21 18:41:05 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

/*
**	Initialize parameters for Julia fractal.
*/

void	init_julia(t_fractol *fractol)
{
	fractol->width = 1600;
	fractol->height = 1000;
	fractol->x = 0;
	fractol->y = 0;
	fractol->i = 0;
	fractol->x1 = -4;
	fractol->x2 = 2.5;
	fractol->y1 = -2.5;
	fractol->y2 = 3;
	fractol->c_r = -0.63;
	fractol->c_i = -0.54;
	fractol->iter_max = 100;
	fractol->zoom = 200;
	fractol->id_frac = 0;
	fractol->mov_julia = 1;
}

/*
**	Calculate, for each iterations
*/

void	exten_julia(t_fractol *fractol)
{
	while (fractol->z_r * fractol->z_r + fractol->z_i
		* fractol->z_i < 4 && fractol->i < fractol->iter_max)
	{
		fractol->tmp = fractol->z_r;
		fractol->z_r = fractol->z_r * fractol->z_r
			- fractol->z_i * fractol->z_i + fractol->c_r;
		fractol->z_i = 2 * fractol->z_i * fractol->tmp + fractol->c_i;
		fractol->i++;
	}
}

/*
**	Create image of Julia fractal.
*/

void	draw_julia(t_fractol *fractol)
{
	while (fractol->y < fractol->height)
	{
		while (fractol->x < fractol->width)
		{
			fractol->c_r = fractol->c_r;
			fractol->c_i = fractol->c_i;
			fractol->z_r = fractol->x / fractol->zoom + fractol->x1;
			fractol->z_i = fractol->y / fractol->zoom + fractol->y1;
			exten_julia(fractol);
			bfr_pix(fractol);
			fractol->i = 50;
			fractol->x++;
		}
		fractol->y++;
		fractol->x = 0;
	}
	fractol->x = 0;
	fractol->y = 0;
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->imgptr, 0, 0);
}
