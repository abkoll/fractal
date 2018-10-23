/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:14:02 by akoller           #+#    #+#             */
/*   Updated: 2017/10/12 15:39:07 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
	const void *restrict src, int c, size_t n)
{
	size_t	t;
	char	*d;
	char	*s;

	t = 0;
	d = (char*)dst;
	s = (char*)src;
	while (t < n)
	{
		d[t] = s[t];
		if ((unsigned char)d[t] == (unsigned char)c)
			return ((char*)d + t + 1);
		t++;
	}
	return (NULL);
}
