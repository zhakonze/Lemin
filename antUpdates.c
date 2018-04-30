/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antUpdates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/22 09:02:30 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		updateants(t_antfarm *farm, int numPaths)
{
	t_ant	*tmpAnt;
	t_path	*path;
	int		index;

	createants(farm);
	tmpAnt = farm->allants;
	while (tmpAnt != NULL)
	{
		tmpAnt->distancecovered = 1;
		if (tmpAnt->antnum % numPaths == 0)
		{
			tmpAnt->pathNumber = numPaths;
			tmpAnt->turntomove = tmpAnt->antnum / numPaths;
		}
		else
		{
			tmpAnt->pathNumber = tmpAnt->antnum % numPaths;
			tmpAnt->turntomove = (int)(tmpAnt->antnum / numPaths) + 1;
		}
		path = farm->allPaths;
		index = 0;
		while (++index != tmpAnt->pathNumber)
			path = path->next;
		tmpAnt->pathtravelthru = path;
		tmpAnt = tmpAnt->next;
	}
}

static void	printAnt(char *room, int ant)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

static char	*getNextRoom(t_ant *ant)
{
	return (ant->pathtravelthru->roomsInPath[ant->distancecovered]);	
}

void			moveants(t_antfarm *farm)
{
	int		turn;
	t_ant	*tmpAnt;
	char	*nextRoom;
	int		movedAnts;

	turn = 1;
	while (1)//turn looping
	{
		movedAnts = 0;
		tmpAnt = farm->allants;
		while (tmpAnt != NULL)
		{
			if (tmpAnt->turntomove <= turn)
			{
				if (tmpAnt->distancecovered < tmpAnt->pathtravelthru->distance)
				{
					nextRoom = getNextRoom(tmpAnt);
					printAnt(nextRoom, tmpAnt->antnum);
					tmpAnt->distancecovered++;
					movedAnts++;
				}
			}
			tmpAnt = tmpAnt->next;
		}
		if (movedAnts == 0)
			break;
		ft_putchar('\n');
		turn++;
	}
}