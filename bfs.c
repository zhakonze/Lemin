/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/22 09:02:30 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		bfssetup(t_antfarm *farm)
{
	t_queue	*queue;
	t_room	*startroom;

	queue = NULL;
	startroom = getroomfromfarm(farm, farm->startroom);
	startroom->visited = 1;
	startroom->visitedBy = startroom->name;
	addToQueue(&queue, startroom->name);
	bfs(farm, &queue);
	cleanunvisited(farm);
}

void		bfs(t_antfarm *farm, t_queue **queue)
{
	int		index;
	t_room	*head;
	t_room	*neighbour;

	while (*queue != NULL)
	{
		head = getroomfromfarm(farm, (*queue)->name);
		index = -1;
		while (head->linked[++index] != NULL)
		{
			neighbour = getroomfromfarm(farm, head->linked[index]);
			if (ft_strequ(head->visitedBy, neighbour->name) == 1)
				continue ;
			if (neighbour->visited == 1)
			{
				clearlink(head->name, neighbour->name, farm);
				index--;
			}
			else if (ft_strequ(farm->endRoom, neighbour->name) == 0)
				setvisitation(neighbour, head, queue);
		}
		removeFromQueue(queue);
	}
}

static char	**removeneighbour(char **linked, char *name)
{
	int		len;
	int		tmpindex;
	int		linkedlndex;
	char	**tmplinked;

	len = 0;
	tmpindex = 0;
	linkedlndex = 0;
	while (linked[len] != NULL)
		len++;
	if ((tmplinked = (char**)malloc(sizeof(char*) * ((len - 1) + 1))) == NULL)
		return (NULL);
	tmplinked[len - 1] = NULL;
	while (tmpindex < len - 1)
	{
		if (ft_strequ(linked[linkedlndex], name) == 1)
			linkedlndex++;
		else
			tmplinked[tmpindex++] = ft_strdup(linked[linkedlndex++]);
	}
	linked = (char**)ft_clear_2d((void**)linked);
	return (tmplinked);
}

void		clearlink(char *name1, char *name2, t_antfarm *farm)
{
	t_room	*r1;
	t_room	*r2;

	r1 = getroomfromfarm(farm, name1);
	r2 = getroomfromfarm(farm, name2);
	r1->linked = removeneighbour(r1->linked, name2);
	r2->linked = removeneighbour(r2->linked, name1);
}

void		cleanunvisited(t_antfarm *farm)
{
	int		index;
	int		linklndex;
	t_room	*room;

	index = 0;
	linklndex = 0;
	room = farm->allRooms;
	while (room != NULL)
	{
		if (room->visited == 0 && ft_strequ(room->name, farm->endRoom) == 0)
		{
			while (room->linked[linklndex] != NULL)
				clearlink(room->name, room->linked[linklndex], farm);
		}
		room = room->next;
	}
}
