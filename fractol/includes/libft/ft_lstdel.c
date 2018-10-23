/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 00:37:26 by akoller           #+#    #+#             */
/*   Updated: 2017/10/09 22:17:25 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *alst;
	if (del)
	{
		while (tmp)
		{
			next = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = next;
		}
		*alst = NULL;
	}
}
