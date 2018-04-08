/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:40:50 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/09 16:39:08 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)ft_memalloc(len + 1);
	if (!str)
		return (NULL);
	if (s)
		while (s[start + i] && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
	return (str);
}
