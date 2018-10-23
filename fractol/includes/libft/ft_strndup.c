/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 12:04:30 by akoller           #+#    #+#             */
/*   Updated: 2017/10/10 17:03:33 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	str = ft_strncpy(str, s1, n);
	str[n] = '\0';
	return (str);
}
