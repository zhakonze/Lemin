/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2018/05/01 09:39:50 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				createfarm(t_antfarm *farm, char *line, int result)
{
	while (result == 1 && get_next_line(0, &line) > 0)
	{
		line = ft_strtrim(line);
		ft_putendl(line);
		if (isnumants(line, farm) == -1)
			result = 0;
		else if (isnumants(line, farm) == 1)
			farm->numants = ft_atoi(line);
		else if (isroom(line, farm) == 1)
			createroom(farm, line);
		else if (islink(line, farm) == 1)
			createlink(farm, line);
		else if (iscommand(line, farm) == 1)
			;
		else if (iscomment(line) == 1)
			continue ;
		else
			result = 0;
	}
	return (result);
}

int				createroom(t_antfarm *farm, char *line)
{
	t_room		*room;
	char		**split;

	room = (t_room*)malloc(sizeof(t_room));
	if (room == NULL)
		return (0);
	else
	{
		split = ft_strsplit(line, ' ');
		room->name = ft_strdup(split[0]);
		room->visited = 0;
		room->visitedby = NULL;
		room->pathmaster = NULL;
		room->lvl = 0;
		room->linked = NULL;
		room->next = NULL;
		if (farm->allrooms == NULL)
			farm->allrooms = room;
		else
		{
			room->next = farm->allrooms;
			farm->allrooms = room;
		}
		split = (char**)ft_clear_2d((void**)split);
		return (1);
	}
}

int				createlink(t_antfarm *farm, char *line)
{
	char		**split;
	t_room		*r1;
	t_room		*r2;

	split = ft_strsplit(line, '-');
	r1 = getroomfromfarm(farm, split[0]);
	r2 = getroomfromfarm(farm, split[1]);
	if (ft_contains(r1->linked, r2->name) == 1)
		return (1);
	else
	{
		addlink(&r1, r2->name);
		addlink(&r2, r1->name);
		return (1);
	}
}

int				createants(t_antfarm *farm)
{
	int			index;
	t_ant		*ant;

	index = farm->numants;
	while (index > 0)
	{
		if ((ant = (t_ant*)malloc(sizeof(t_ant))) == NULL)
			return (0);
		ant->antnum = index;
		ant->next = NULL;
		ant->pathtravelthru = NULL;
		ant->pathnumber = 0;
		ant->distancecovered = 0;
		ant->turntomove = 0;
		if (farm->allants == NULL)
			farm->allants = ant;
		else
		{
			ant->next = farm->allants;
			farm->allants = ant;
		}
		index--;
	}
	return (1);
}

t_path			*createpath(t_antfarm *farm, int distance)
{
	t_path		*path;

	path = (t_path*)malloc(sizeof(t_path));
	if (path == NULL)
		return (NULL);
	else
	{
		path->next = NULL;
		path->distance = distance;
		path->roomsinpath = (char**)malloc(sizeof(char*) * (distance + 1));
		path->roomsinpath[distance] = NULL;
		path->roomsinpath[distance - 1] = ft_strdup(farm->endroom);
		path->roomsinpath[0] = ft_strdup(farm->startroom);
		return (path);
	}
}
