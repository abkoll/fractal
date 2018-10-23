/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:21:31 by akoller           #+#    #+#             */
/*   Updated: 2018/09/03 22:21:35 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key_hook(int key, t_env *e)
{
	key == KEY_RIGHT ? e->xtrans -= 10 : 0;
	key == KEY_LEFT ? e->xtrans += 10 : 0;
	key == KEY_UP ? e->ytrans += 10 : 0;
	key == KEY_DOWN ? e->ytrans -= 10 : 0;
	key == KEY_PLUS || key == KEY_STDEQU ? e->zoom /= 1.1 : 0;
	key == KEY_MINUS || key == KEY_STDMIN ? e->zoom *= 1.1 : 0;
	key == KEY_H ? e->maxiter += 10 : 0;
	key == KEY_G && (e->maxiter > 17) ? e->maxiter -= 10 : 0;
	key == KEY_SPACE ? e->text-- : 0;
	if (key == KEY_N)
		e->fract > 0 ? e->fract = 0 : e->fract++;
	key == KEY_ESC ? exit(0) : 0;
	ft_thread(e);
	return (0);
}

int		ft_mouse_move(int x, int y, t_env *e)
{
	if (e->mousex == x && e->mousey == y)
		return (0);
	e->mousex = x;
	e->mousey = y;
	ft_thread(e);
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, t_env *e)
{
	(void)button;
	(void)x;
	(void)y;
	(void)e;
	// e->mousex = x;
	// e->mousey = y;
	//ft_initialize(e);
	//ft_thread(e);
	return (0);
}