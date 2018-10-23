/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:24:35 by akoller           #+#    #+#             */
/*   Updated: 2017/10/12 15:28:38 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *restrict dst,
			const char *restrict src, size_t size)
{
	size_t		i;
	size_t		j;
	const char	*s;
	char		*d;

	i = size;
	s = src;
	d = dst;
	while (i-- != 0 && *d != '\0')
		d++;
	j = d - dst;
	i = size - j;
	if (i == 0)
		return (j + ft_strlen(s));
	while (*s != '\0')
	{
		if (i != 1)
		{
			*d++ = *s;
			i--;
		}
		s++;
	}
	*d = '\0';
	return (j + (s - src));
}
