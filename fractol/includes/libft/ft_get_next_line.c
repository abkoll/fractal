/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:14:27 by akoller           #+#    #+#             */
/*   Updated: 2018/01/07 20:55:40 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*getfd(t_list **list, int fd)
{
	t_list			*tmp;

	tmp = *list;
	while (tmp)
	{
		if (fd == (int)tmp->content_size)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(list, tmp);
	return (tmp);
}

static int		nextline(t_list *head, char **line)
{
	char			*tmp;
	char			*next;

	next = ft_strchr(head->content, '\n');
	next[0] = '\0';
	tmp = head->content;
	*line = ft_strdup(head->content);
	head->content = ft_strdup(next + 1);
	ft_strdel(&tmp);
	return (1);
}

static int		extra(t_list *head, char **line)
{
	*line = ft_strdup(head->content);
	if (*(char*)head->content)
		ft_bzero((void*)head->content, sizeof(head->content));
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	t_list			*head;
	char			buff[BUFF_SIZE + 1];
	static t_list	*list;
	size_t			ret;

	if ((BUFF_SIZE <= 0) || fd < 0 || !line || (read(fd, buff, 0) < 0))
		return (-1);
	head = getfd(&list, fd);
	while (!ft_strchr(head->content, '\n') &&
		(ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		head->content = ft_strnjoin(head->content, buff, 1);
	}
	if (ft_strchr(head->content, '\n'))
		return (nextline(head, line));
	if (*(char*)head->content)
		return (extra(head, line));
	*line = NULL;
	return (0);
}
