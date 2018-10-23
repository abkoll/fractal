/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:26:53 by akoller           #+#    #+#             */
/*   Updated: 2017/10/10 16:55:47 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*b;
	const char	*l;

	if (*little == '\0')
		return ((char*)big);
	while (*big)
	{
		b = big;
		l = little;
		while (*l && *b == *l)
		{
			b++;
			l++;
		}
		if (*l == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
