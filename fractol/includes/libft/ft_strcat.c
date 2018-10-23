/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:22:30 by akoller           #+#    #+#             */
/*   Updated: 2017/10/10 17:59:15 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char	*src;
	char	*dst;
	size_t	i;

	i = 0;
	dst = s1;
	src = (char*)s2;
	while (dst[i] != '\0')
		i++;
	while (*src != '\0')
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (s1);
}
