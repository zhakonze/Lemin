/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/22 09:02:30 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int        ft_isnumber(char *str)
{
    int index;

    index = 0;
    if ((str[index] == '-' || str[index] == '+') && str[index + 1] != '\0')
        index++;
    while (str[index])
    {
        if (!ft_isdigit(str[index]))
            return (0);
        index++;
    }
    return (1);
}