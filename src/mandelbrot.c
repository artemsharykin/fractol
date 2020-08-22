/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 13:55:37 by yalona            #+#    #+#             */
/*   Updated: 2020/08/22 13:20:44 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	exten_mandelbrot(t_fractol *fractol)
{
	while (fractol->z_r * fractol->z_r + fractol->z_i * fractol->z_i < 4
			&& fractol->i < fractol->iter_max)
	{
		fractol->tmp = fractol->z_r;
		fractol->z_r = fractol->z_r * fractol->z_r - fractol->z_i
			* fractol->z_i + fractol->c_r;
		fractol->z_i = 2 * fractol->z_i * fractol->tmp + fractol->c_i;
		fractol->i++;
	}
}

void	init_mandelbrot(t_fractol *fractol)
{
	fractol->width = 1600;
	fractol->height = 1000;
	fractol->x = 0;
	fractol->y = 0;
	fractol->i = 0;
	fractol->x1 = -5.5;
	fractol->x2 = 2.5;
	fractol->y1 = -3.25;
	fractol->y2 = 3;
	fractol->iter_max = 40;
	fractol->zoom = 150;
	fractol->id_frac = 2;
}

void	draw_mandelbrot(t_fractol *fractol)
{
	while (fractol->y < fractol->height)
	{
		while (fractol->x < fractol->width)
		{
			fractol->c_r = fractol->x / fractol->zoom + fractol->x1;
			fractol->c_i = fractol->y / fractol->zoom + fractol->y1;
			fractol->z_r = 0;
			fractol->z_i = 0;
			exten_mandelbrot(fractol);
			bfr_pix(fractol);
			fractol->i = 0;
			fractol->x++;
		}
		fractol->y++;
		fractol->x = 0;
	}
	fractol->x = 0;
	fractol->y = 0;
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->imgptr, 0, 0);
}
