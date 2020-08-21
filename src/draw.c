/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:59:12 by yalona            #+#    #+#             */
/*   Updated: 2020/08/21 15:32:04 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"
#include <pthread.h>

void	bfr_pix(t_fractol *fractol)
{
	if (fractol->i == fractol->iter_max)
		pix_to_img(fractol, 0);
	else
	{
		if (fractol->id_frac == 4)
			pix_to_img(fractol, (fractol->i * 900000));
		else
			pix_to_img(fractol, (fractol->i * 1100000));
	}
}

void	pix_to_img(t_fractol *fractol, int color)
{
	fractol->color = mlx_get_color_value(fractol->mlx, color);
	ft_memmove(fractol->imgstr + (4 * (fractol->width * fractol->y))
		+ (fractol->x * 4), &fractol->color, sizeof(int));
}

void	zoom(t_fractol *fractol, int x, int y)
{
	double x_n;
	double y_n;

	if (y > 0 && x > 0)
	{
		x_n = (x / fractol->zoom) + fractol->x1;
		y_n = (y / fractol->zoom) + fractol->y1;
		fractol->zoom *= 1.35;
		fractol->x1 = x_n - (x / fractol->zoom);
		fractol->y1 = y_n - (y / fractol->zoom);
		lounch_draw(fractol);
	}
}

void	dezoom(t_fractol *fractol, int x, int y)
{
	double x_n;
	double y_n;

	x_n = (x / fractol->zoom) + fractol->x1;
	y_n = (y / fractol->zoom) + fractol->y1;
	fractol->zoom /= 1.35;
	fractol->x1 = x_n - (x / fractol->zoom);
	fractol->y1 = y_n - (y / fractol->zoom);
	lounch_draw(fractol);
}