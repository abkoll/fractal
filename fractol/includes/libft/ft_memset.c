/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 21:16:10 by akoller           #+#    #+#             */
/*   Updated: 2017/10/10 17:55:22 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *pointer;

	pointer = (unsigned char *)b;
	while (len > 0)
	{
		pointer[len - 1] = c;
		len--;
	}
	return (b);
}
