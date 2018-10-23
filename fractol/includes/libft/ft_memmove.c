/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:15:11 by akoller           #+#    #+#             */
/*   Updated: 2017/10/10 16:37:27 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*sptr;
	char	*dptr;

	sptr = (char*)src;
	dptr = (char*)dst;
	if (sptr < dptr)
	{
		sptr = sptr + len - 1;
		dptr = dptr + len - 1;
		while (len > 0)
		{
			*dptr-- = *sptr--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*dptr++ = *sptr++;
			len--;
		}
	}
	return (dst);
}
