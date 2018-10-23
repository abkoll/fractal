/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 09:39:42 by akoller           #+#    #+#             */
/*   Updated: 2018/06/20 10:07:46 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <stdbool.h>
#include <pthread.h>

#include "includes/libft/libft.h"
#include "includes/libmlx/mlx.h"
#include "includes/keys.h"

#define	THREADS	8	
#define WIN_HEIGHT 1024
#define WIN_WIDTH 1024
#define HUE_DEG 120

typedef	struct	s_env
{
	bool		usage;
	bool		text;
	int			fract;
	int			bpp;
	int			size;
	int			endian;
	double		zoom;
	int			maxiter;
	double		xtrans;
	double		ytrans;
	double		x0;
	double		x;
	double		y0;
	double		y;
	double		tmp;
	double		log_zn;
	double		nu;
	double		color1;
	double		color2;
	double		color;
	pthread_t	threadnum[THREADS];
	double		mousex;
	double		mousey;
	void		*image;
	int			*data;
	void		*mlx;
	void		*win;	
}				t_env;

typedef	struct	s_thread
{
	int			id;
	t_env		*env;
}				t_thread;

typedef	struct 	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef	int		(g_fract)(t_env *env, double px, double py);

typedef	struct 	s_map
{
	char		*name;
	g_fract		*fractol;
}				t_map;

int				ft_mouse_move(int x, int y, t_env *e);
int				ft_mandelbrot(t_env *env, double px, double py);
int				ft_julia(t_env *e, double px, double py);
void			ft_initialize(t_env *env);
int				ft_hsltorgb(double h, float s, float l);
int				ft_key_hook(int key, t_env *env);
int				ft_mouse_hook(int button, int x, int y, t_env *e);
void			ft_helptext(t_env *env);
//void			ft_frame(t_env *env, int thread_start, int thread_end);
void			ft_thread(t_env *env);
int				ft_color(int hue, t_env *env);

#endif
