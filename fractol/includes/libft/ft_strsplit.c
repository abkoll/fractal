/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:43:50 by akoller           #+#    #+#             */
/*   Updated: 2017/10/11 21:20:33 by akoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordlen(char const *str, char c)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	while (str[i + j] != c && str[i + j] != '\0')
		j++;
	return (j);
}

static int		ft_twrd(char const *src, char c)
{
	int			wordcount;
	const char	*s;

	wordcount = 0;
	s = src;
	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
			wordcount++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (wordcount);
}

char			**ft_strsplit(char const *s, char c)
{
	int			j;
	int			h;
	char		**rs;
	int			total_words;

	if (s == NULL || c == 0)
		return (NULL);
	total_words = ft_twrd(s, c);
	j = 0;
	if (!(rs = (char**)malloc(sizeof(char *) * (total_words + 1))))
		return (NULL);
	while (total_words--)
	{
		h = 0;
		rs[j] = (char*)malloc(sizeof(char) * ft_wordlen(s, c));
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s != '\0')
			rs[j][h++] = *s++;
		rs[j++][h] = '\0';
	}
	rs[j] = NULL;
	return (rs);
}
