/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:18:41 by akoller           #+#    #+#             */
/*   Updated: 2017/10/10 17:27:13 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = ft_strlen(s1) + 1;
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (0);
	else
		ft_strcpy(str, s1);
	return (str);
}
