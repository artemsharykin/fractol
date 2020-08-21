/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:20:00 by yalona            #+#    #+#             */
/*   Updated: 2020/08/21 18:54:04 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

//int	mouse_julia(t_fractol *fractol, int x, int y)
int	mouse_julia(int x, int y, t_fractol *fractol)
{
	if (fractol->mov_julia == 1)
    {
        if (x < fractol->width && y < fractol->height)
        {
            if (x < fractol->width / 2 && y < fractol->height / 2)
                fractol->c_r += 0.004;
            if (x > fractol->width / 2 && y < fractol->height / 2)
                fractol->c_r -= 0.004;
            if (x < fractol->width / 2 && y > fractol->height / 2)
                fractol->c_i += 0.004;
            if (x > fractol->width / 2 && y > fractol->height / 2)
                fractol->c_i += 0.004;
        }
        draw_julia(fractol);
    }
    return (0);
}

//int	keys(t_fractol *fractol, int keycode)
int	    keys(int keycode,t_fractol *fractol)
{   
    if (keycode == 53)
        exit(0);
    if (keycode == 37)
    {
        if ( fractol->mov_julia == 1)
            fractol->mov_julia = 0;
        else
            fractol->mov_julia = 1;
    }
    return (0);
}

//int	mouse_press(t_fractol *fractol, int mousecode, int x, int y)
int	mouse_press(int mousecode, int x, int y, t_fractol *fractol)
{
    if (mousecode == 4 || mousecode == 1)
    {
        zoom(fractol, x, y);
        lounch_draw(fractol);
    }
    else if (mousecode == 5 || mousecode == 2)
    {
        dezoom(fractol, x, y);
        lounch_draw(fractol);
    }
    return (0);
}
