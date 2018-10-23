/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:23:19 by akoller           #+#    #+#             */
/*   Updated: 2017/10/10 17:47:46 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*src;
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dst = s1;
	src = (char*)s2;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (s1);
}
