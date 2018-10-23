/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:13:01 by akoller           #+#    #+#             */
/*   Updated: 2017/10/12 15:29:31 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *restrict dst,
		const void *restrict src, size_t n)
{
	size_t	t;
	char	*d;
	char	*s;

	t = 0;
	d = (char *)dst;
	s = (char *)src;
	while (t < n)
	{
		d[t] = s[t];
		t++;
	}
	return (dst);
}
