/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 14:54:07 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/21 14:41:59 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		loop1;
	size_t		loop2;

	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	loop1 = 0;
	while (s1[loop1] != '\0')
	{
		loop2 = 0;
		while (s2[loop2] != '\0' && s1[loop1 + loop2] != '\0' && s2[loop2] ==
				s1[loop1 + loop2])
			loop2++;
		if (loop2 == ft_strlen(s2))
			return ((char*)(&(s1[loop1])));
		loop1++;
	}
	return (NULL);
}
