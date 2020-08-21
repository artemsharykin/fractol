/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:55:53 by yalona            #+#    #+#             */
/*   Updated: 2020/08/21 17:29:52 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void lounch_draw(t_fractol *fractol)
{
    if (fractol->id_frac == 1)
        draw_julia(fractol);
    else if (fractol->id_frac == 2)
        draw_mandelbrot(fractol);
    else if (fractol->id_frac == 3)
        draw_burningship(fractol);
    
    
}

void    ft_map(t_fractol *fractol)
{
    fractol->mlx = mlx_init;
    fractol->win = mlx_new_window(fractol->mlx, fractol->width, 
        fractol->height, "FRACTOL");
    fractol->imgptr = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
    fractol->imgstr = mlx_get_data_addr(fractol->imgptr, 
    &(fractol->bpp), &(fractol->s_l), &(fractol->endian));
    lounch_draw(fractol);
    mlx_key_hook(fractol->win, keys, fractol);
    if (fractol->id_frac == 1)
        mlx_hook(fractol->win, 6, 1L, mouse_julia, fractol);
        mlx_mouse_hook(fractol->win, mouse_press, fractol);
        mlx_hook(fractol->win, 17, 0, exit_cl, NULL);
        mlx_loop(fractol->mlx);
        }

int inst_fractol(t_fractol *fractol, char *name)
{
    if(ft_strcmp (name, "julia") == 0)
    {
        init_julia(fractol);
        fractol->id_frac = 1;
    }
    else if(ft_strcmp(name, "mandelbrot") == 0)
    {
        init_mandelbrot(fractol);
        fractol->id_frac = 2;
    }
    else if (ft_strcmp(name, "burningship") == 0)
    {
        init_burningship(fractol);
        fractol->id_frac = 3;
    }
    else
    {
        return(0);
    }
    return(1);
}
int main(int ac, char **av)
{
    t_fractol fractol;
    if ((ac != 2) || inst_fractol(&fractol, av[1]) == 0)
        return(usage());
    ft_map(&fractol);
    return(0);
}
