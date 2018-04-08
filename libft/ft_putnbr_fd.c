/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 09:02:16 by zhakonze          #+#    #+#             */
/*   Updated: 2017/05/31 14:35:19 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		min_int(int sign, int fd)
{
	if (sign)
		ft_putstr_fd("-2147483648", fd);
	else
		ft_putstr_fd("2147483647", fd);
}

void			ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		return (min_int(1, fd));
	else if (nb == 2147483647)
		return (min_int(0, fd));
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + 48, fd);
}
