/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 09:26:18 by akoller           #+#    #+#             */
/*   Updated: 2018/06/21 13:17:07 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"	

t_map	g_map_array[] =
{
	{"m", &ft_mandelbrot},
	{"j", &ft_julia},
};

int		ft_color(int hue, t_env *env)
{
	int		rgb[3];
	int		i;

	if (hue >= env->maxiter)
		return (0);
	hue %= HUE_DEG;
	i = -1;
	ft_bzero(rgb, 3 * (sizeof(int)));
	rgb[0] = (0xff / (HUE_DEG / 6)) * (HUE_DEG / 6);
	while (++i < hue)
	{
		if (i < (HUE_DEG / 6))
			rgb[1] += 0xff / (HUE_DEG / 6);
		if (i >= (HUE_DEG / 6) && i < (2 * HUE_DEG / 6))
			rgb[0] -= 0xff / (HUE_DEG / 6);
		if (i >= (2 * HUE_DEG / 6) && i < (3 * HUE_DEG / 6))
			rgb[2] += 0xff / (HUE_DEG / 6);
		if (i >= (3 * HUE_DEG / 6) && i < (4 * HUE_DEG / 6))
			rgb[1] -= 0xff / (HUE_DEG / 6);
		if (i >= (4 * HUE_DEG / 6) && i < (5 * HUE_DEG / 6))
			rgb[0] += 0xff / (HUE_DEG / 6);
		if (i >= (5 * HUE_DEG / 6))
			rgb[2] -= 0xff / (HUE_DEG / 6);
	}
	return (((rgb[0] & 0xff) << 16) | ((rgb[1] & 0xff) << 8) | (rgb[2] & 0xff));
}

// void	ft_frame(t_env *env, int tstart, int tend)
// {
// 	double	x;
// 	int		i;

// 	while (++tstart < tend)
// 	{
// 		x = -1;
// 		while (++x < WIN_WIDTH)
// 		{
// 			i = g_map_array[env->fract].fractol(env, x, (double)tstart);
// 			env->data[(int)x + (tstart * WIN_WIDTH)] = ft_color(i, env);
// 		}
// 	}
// }

void		*ft_threadplace(void *e)
{
	int		i;
	int		color;
	int		x;
	int		y;
	t_thread	*argp;

	argp = (t_thread *)e;
	i = -1;
	y = *((int*) e);
	t_env 	*env = argp->env;
	while (++i < (WIN_HEIGHT / THREADS))
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			color = g_map_array[env->fract].fractol(env, x, y);
			//*(int *)(env->data + (x + y * (env->size >> 2)) * env->bpp) = ft_color(color, env);
			env->data[x + (y * WIN_WIDTH)] = ft_color(color, env);
		}
		y += THREADS;
	}
	pthread_exit(0);
}

void			ft_thread(t_env *env)
{
	int			i;
	t_thread	argp[THREADS];

	i = -1;
 	ft_bzero(env->data, sizeof(int) * WIN_HEIGHT * WIN_WIDTH);
 	//mlx_clear_window(env->mlx, env->win);
 	while (++i < THREADS)
 	{
 		argp[i] = (t_thread){.id = i, .env = env};
 		pthread_create(&env->threadnum[i], NULL, ft_threadplace, &argp[i]);
 	}
 	i = -1;
 	while (++i < THREADS)
 	{
 		pthread_join(env->threadnum[i], NULL);
 	}
 	mlx_put_image_to_window(env->mlx, env->win, env->image, 0, 0);
 	ft_helptext(env);
}

void		ft_initialize(t_env *env)
{
	env->text = 1;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	mlx_hook(env->win, 2, 0, &ft_key_hook, env);
	mlx_hook(env->win, 0, 0, &ft_mouse_move, env);
	mlx_mouse_hook(env->win, &ft_mouse_hook, env);
//	mlx_expose_hook(env->win, ) //redraws a part of the window
//	mlx_loop_hook(env->mlx, ft_newimage, env);
	env->image = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	env->data = (int*)mlx_get_data_addr(env->image, &env->bpp, &env->size, 
	&env->endian); //poss change data to int* for rgb conversion
	env->maxiter = 84;
	env->xtrans = WIN_WIDTH / 2;
	env->ytrans = WIN_HEIGHT / 2;
	env->zoom = 1;
	env->x0 = 0;
	env->y0 = 0;
	ft_thread(env);
//	ft_helptext(env);
	mlx_loop(env->mlx);
}

float		ft_linear_interpolate(float v0, float v1, float t)
{
	float	lerp = (1 - t) * v0 + t * v1;

	return (lerp);
}

int			ft_julia(t_env *e, double px, double py)
{
	double	i;

	i = -1;
	e->x0 = (px - e->xtrans) / (WIN_WIDTH / 2) * e->zoom;
	e->y0 = (py - e->ytrans) / (WIN_HEIGHT / 2) * e->zoom;
	while (e->x0 * e->x0 + e->y0 * e->y0 <= 4 && ++i < e->maxiter) 
    {
        e->tmp = e->y0; //e->x0 * e->x0 - e->y0 * e->y0;
        e->y0 = 2 * e->x0 * e->y0 + e->mousey; 
        e->x0 = e->x0 * e->x0 - e->tmp * e->tmp + e->mousex; //e->tmp + e->mousex;
    }
    if (i == e->maxiter)
        return (0);
    return (i);

//     Complex z = new Complex(x,y);
// double smoothcolor = Math.exp(-z.abs());

// for(i=0;i<max_iter && z.abs() < 30;i++) {
//     z = f(z);
//     smoothcolor += Math.exp(-z.abs());
// }
}

int			ft_mandelbrot(t_env *e, double px, double py)
{
	double	i;

	i = -1;
	e->x0 = (px - (e->xtrans * 1.5)) / (WIN_WIDTH / 2) * e->zoom + 0;
	e->y0 = (py - e->ytrans) / (WIN_HEIGHT / 2) * e->zoom + 0;
	e->x = e->x0;
	e->y = e->y0;
	while (e->x * e->x + e->y * e->y < (1 << 16) && ++i < e->maxiter)
	{
		e->tmp = e->x * e->x - e->y * e->y + e->x0;
		e->y = 2 * e->x * e->y + e->y0;
		e->x = e->tmp;
	}
	if (i < e->maxiter)
	{
		e->log_zn = log(e->x * e->x + e->y * e->y) / 2;
		e->nu = log(e->log_zn / log(2)) / log(2);
		i = i + 1 - e->nu;
	}
	e->color1 = ft_color((int)i, e); //ft_huetorgb((float)i, ); //populate dis;
	e->color2 = ft_color((int)i+1, e);
	e->color = ft_linear_interpolate(e->color1, e->color2, (i - (int)i));

	return (i);
}

int		main(int ac, char **av)
{
	t_env	env;
	int		i;

	i = -1;
	env.usage = 1;
	env.fract = 0;
	if (ac != 2)
		ft_error("Usage: ./fractol [m|j]");
	while (++i < 2 && g_map_array[i].name && av[1])
	{
		if (!ft_strcmp(g_map_array[i].name, av[1]))
		{
			env.fract = i;
			env.usage = 0;
			ft_initialize(&env);
		}
	}
	if (env.usage)
		ft_error("Usage: ./fractol [m|j]");
}
