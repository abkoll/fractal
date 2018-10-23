/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:43:59 by akoller           #+#    #+#             */
/*   Updated: 2017/11/20 10:06:48 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int i)
{
	char	*string;

	string = ft_strjoin(s1, s2);
	if (i == 1 || i == 3)
	{
		free((void*)s1);
		s1 = NULL;
	}
	else if (i == 2 || i == 3)
	{
		free((void*)s2);
		s2 = NULL;
	}
	return ((char*)string);
}
