/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmatle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 19:49:48 by pmatle            #+#    #+#             */
/*   Updated: 2017/05/26 14:16:55 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, int size)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (big[x] != '\0' && x < size)
	{
		y = 0;
		while (big[x + y] == little[y] && (x + y < size))
		{
			y++;
			if (little[y] == '\0')
				return ((char*)(big + x));
		}
		x++;
	}
	return (NULL);
}
