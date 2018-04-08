/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 09:02:16 by zhakonze          #+#    #+#             */
/*   Updated: 2017/05/31 14:35:49 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		min_int(int sign)
{
	if (sign)
		ft_putstr("-2147483648");
	else
		ft_putstr("2147483647");
}

void			ft_putnbr(int nb)
{
	if (nb == -2147483648)
		return (min_int(1));
	else if (nb == 214783647)
		return (min_int(0));
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}
