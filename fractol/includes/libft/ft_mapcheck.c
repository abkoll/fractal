/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:15:31 by akoller           #+#    #+#             */
/*   Updated: 2018/01/11 21:15:49 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mapcheck(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if ((!ft_isdigit(c[i])) && c[i] != ' ' && c[i] != '-')
			ft_error("Error: forbidden characters");
		if ((c[i] == '-') && (!ft_isdigit(c[i + 1])))
			ft_error("Error: forbidden usage");
		if ((c[i] == '-') && (c[i + 1] == '0'))
			ft_error("Error: zero cannot be negative");
		i++;
	}
}
