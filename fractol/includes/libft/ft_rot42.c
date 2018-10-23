/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 22:21:31 by akoller           #+#    #+#             */
/*   Updated: 2017/10/12 15:58:41 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rotate(char c)
{
	int		i;
	int		result;

	i = 0;
	result = c;
	if (!(c >= 'a' && c <= 'z' && c >= 'A' && c <= 'Z'))
		return (c);
	while (i < 42)
	{
		result++;
		if (result == 'z' + 1 || result == 'Z' + 1)
			result -= 'z' - 'a' + 1;
		i++;
	}
	return (result);
}

char		*ft_rot42(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_rotate(str[i]);
		i++;
	}
	return (str);
}
