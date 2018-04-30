/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 08:59:51 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/10 10:12:25 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_splitcounter(char const *s, char c)
{
	int					i;
	size_t				size;

	i = 0;
	size = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			size++;
		}
	}
	return (size);
}

char					**ft_strsplit(char const *s, char c)
{
	char				**str;
	size_t				size;
	int					i;
	int					start;

	if (!s || !(str = (char **)malloc(sizeof(char *) * (ft_splitcounter(s, c)
		+ 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			str[size++] = ft_strsub(s, start, i - start);
		}
	}
	str[size] = NULL;
	return (str);
}
