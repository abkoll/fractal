/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:21:19 by akoller           #+#    #+#             */
/*   Updated: 2017/10/10 18:11:53 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	t;

	t = 0;
	while (src[t] && t < len)
	{
		dst[t] = src[t];
		t++;
	}
	while (t < len)
	{
		dst[t] = '\0';
		t++;
	}
	return (dst);
}
