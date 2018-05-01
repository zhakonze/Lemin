/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antUpdates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2018/05/01 08:22:48 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		updateants(t_antfarm *farm, int numpaths)
{
	t_ant	*tmpant;
	t_path	*path;
	int		index;

	createants(farm);
	tmpant = farm->allants;
	while (tmpant != NULL)
	{
		tmpant->distancecovered = 1;
		if (tmpant->antnum % numpaths == 0)
		{
			tmpant->pathnumber = numpaths;
			tmpant->turntomove = tmpant->antnum / numpaths;
		}
		else
		{
			tmpant->pathnumber = tmpant->antnum % numpaths;
			tmpant->turntomove = (int)(tmpant->antnum / numpaths) + 1;
		}
		path = farm->allpaths;
		index = 0;
		while (++index != tmpant->pathnumber)
			path = path->next;
		tmpant->pathtravelthru = path;
		tmpant = tmpant->next;
	}
}

static void	printant(char *room, int ant)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

static char	*getnextroom(t_ant *ant)
{
	return (ant->pathtravelthru->roomsinpath[ant->distancecovered]);
}

void		moveants(t_antfarm *farm)
{
	int		turn;
	t_ant	*tmpant;
	char	*nextroom;
	int		movedants;

	turn = 1;
	while (1)
	{
		movedants = 0;
		tmpant = farm->allants;
		while (tmpant != NULL)
		{
			if (tmpant->turntomove <= turn)
			{
				if (tmpant->distancecovered < tmpant->pathtravelthru->distance)
				{
					nextroom = getnextroom(tmpant);
					printant(nextroom, tmpant->antnum);
					tmpant->distancecovered++;
					movedants++;
				}
			}
			tmpant = tmpant->next;
		}
		if (movedants == 0)
			break ;
		ft_putchar('\n');
		turn++;
	}
}
