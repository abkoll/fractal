/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:17:10 by akoller           #+#    #+#             */
/*   Updated: 2017/10/10 17:50:37 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	t;
	char	*str1;
	char	*str2;

	str1 = (char*)s1;
	str2 = (char*)s2;
	t = 0;
	while (t < n)
	{
		if (str1[t] != str2[t])
			return ((unsigned char)str1[t] - (unsigned char)str2[t]);
		t++;
	}
	return (0);
}
