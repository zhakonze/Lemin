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

<<<<<<< HEAD
void		updateants(t_antfarm *farm, int numpaths)
=======
void		updateants(t_antfarm *farm, int numPaths)
>>>>>>> f693f4a5c8f62631eb39244c0736a337f3601171
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

<<<<<<< HEAD
static void	printant(char *room, int ant)
=======
static void	printAnt(char *room, int ant)
>>>>>>> f693f4a5c8f62631eb39244c0736a337f3601171
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

<<<<<<< HEAD
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
=======
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
>>>>>>> f693f4a5c8f62631eb39244c0736a337f3601171
