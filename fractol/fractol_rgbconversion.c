/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_rgbconversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 20:46:01 by akoller           #+#    #+#             */
/*   Updated: 2018/09/02 20:46:04 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	ft_huetorgb(float v1, float v2, float h)
{
	if (h < 0)
		h += 1;
	if (h > 1)
		h -= 1;
	if ((6 * h) < 1)
		return (v1 + (v2 - v1) * 6 * h);
	if ((2 * h ) < 1)
		return (v2);
	if ((3 * h) < 2)
		return (v1 + (v2 - v1) * ((2.0f / 3) - h) * 6);
	return (v1);
}

int	ft_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	unsigned int rgb;

	rgb = 0;
	rgb |= (r << 16);
	rgb |= (g << 8);
	rgb |= (b);

	return (rgb); 
}

int	ft_hsltorgb(double h, float s, float l)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	float			v1;
	float			v2;

	if (s == 0)
	{
		r = (unsigned char)(l * 255);
		g = (unsigned char)(l * 255);
		b = (unsigned char)(l * 255);
	}
	else
	{
		v2 = (l < 0.5) ? (l * (1 + s)) : ((l + s) - (l * s));
		v1 = 2 * l - v2;
		r = (unsigned char)(255 * ft_huetorgb(v1, v2, h + (1.0f / 3)));
		g = (unsigned char)(255 * ft_huetorgb(v1, v2, h));
		b = (unsigned char)(255 * ft_huetorgb(v1, v2, h - (1.0f / 3)));
	}
	return (ft_rgb(r, g, b));
}

void	ft_helptext(t_env *env)
{
	int				i;
	char			*text[9];
	unsigned int	color;
	double			hue;

	hue = 0;
	if (env->text)
	{
	i = -1;
	text[0] = "Instructions:";
	text[1] = "Use arrows to shift image";
	text[2] = "+ to zoom in";
	text[3] = "- to zoom out";
	text[4] = "Space to toggle help menu";
	text[5] = "N to switch fractal";
	text[6] = "G and H to decrease/increase iterations";
	text[7] = "ESC to Quit";
	while (i++ < 7)
	{
		color = ft_hsltorgb(hue, 1, 0.5);
		mlx_string_put(env->mlx, env->win, 20, 20 + (i * 20), color, text[i]);
		hue += 0.1;
	}
}
}
