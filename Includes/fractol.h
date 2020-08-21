/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalona <yalona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:28:19 by yalona            #+#    #+#             */
/*   Updated: 2020/08/21 18:50:48 by yalona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*imgptr;
	void		*imgstr;
	int			endian;
	int			s_l;
	int			bpp;
	int			x;
	int			y;
	int			i;
	int			color;
	double	zoom;
	double	pr;
	double	pi;
	int			iter_max;
	int			width;
	int			height;
	int			id_frac;
	double	z_r;
	double	z_i;
	double	tmp;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	c_r;
	double	c_i;
	int			mov_julia;
}				t_fractol;

void			bfr_pix(t_fractol *fractol);
void			pix_to_img(t_fractol *fractol, int color);
void			zoom(t_fractol *fractol, int x, int y);
void			dezoom(t_fractol *fractol, int x, int y);
//int				mouse_julia(t_fractol *fractol, int x, int y);
int				mouse_julia(int x, int y, t_fractol *fractol);
//int				keys(t_fractol *fractol, int keycode);
int				keys(int keycode,t_fractol *fractol);
//int				mouse_press(t_fractol *fractol, int mousecode, int x, int y);
int				mouse_press(int mousecode, int x, int y, t_fractol *fractol);
void			init_julia(t_fractol *fractol);
void			exten_julia(t_fractol *fractol);
void			draw_julia(t_fractol *fractol);
void			ft_map(t_fractol *fractol);
int				inst_fractol(t_fractol *fractol, char *name);
void			lounch_draw(t_fractol *fractol);
void			exten_mandelbrot(t_fractol *fractol);
void			init_mandelbrot(t_fractol *fractol);
void			draw_mandelbrot(t_fractol *fractol);
int				exiterror(void);
int				exit_cl(void);
int				error(void);
int				usage(void);
//int				mouse_julia(t_fractol *fractol, int x, int y);
void			init_burningship(t_fractol *fractol);
void			draw_burningship(t_fractol *fractol);
void			exten_burninship(t_fractol *fractol);
#endif
