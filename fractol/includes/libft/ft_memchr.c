/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:16:09 by akoller           #+#    #+#             */
/*   Updated: 2017/10/10 16:59:40 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	t;
	char	*d;

	d = (char*)s;
	t = 0;
	while (t < n)
	{
		if ((unsigned char)d[t] == (unsigned char)c)
			return ((char*)s + t);
		t++;
	}
	return (NULL);
}
