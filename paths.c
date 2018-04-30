/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2018/05/01 11:33:13 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path			*poppath(t_path **allpaths)
{
	t_path		*poppedpath;

	poppedpath = *allpaths;
	*allpaths = poppedpath->next;
	poppedpath->next = NULL;
	return (poppedpath);
}

static void		pushpath(t_path **allpaths, t_path *pushedpath)
{
	if (*allpaths == NULL)
		*allpaths = pushedpath;
	else
	{
		pushedpath->next = *allpaths;
		*allpaths = pushedpath;
	}
}

void			sortpath(t_path **allpaths)
{
	t_path		*holder;
	t_path		*sortedpaths;

	holder = NULL;
	sortedpaths = NULL;
	while (*allpaths != NULL)
	{
		holder = poppath(allpaths);
		while (holder != NULL)
		{
			if (sortedpaths == NULL ||
					(holder->distance <= sortedpaths->distance))
			{
				pushpath(&sortedpaths, holder);
				holder = NULL;
			}
			else
				pushpath(allpaths, poppath(&sortedpaths));
		}
	}
	*allpaths = sortedpaths;
}

void			addpathtopaths(t_path **allpaths, t_path *apath)
{
	if (*allpaths == NULL)
		*allpaths = apath;
	else
	{
		apath->next = *allpaths;
		*allpaths = apath;
	}
}

void			getpaths(t_antfarm *farm)
{
	int			index;
	int			revindex;
	t_room		*neighbour;
	t_path		*new_path;
	t_room		*endroom;

	endroom = getroomfromfarm(farm, farm->endroom);
	index = 0;
	while (endroom->linked[index] != NULL)
	{
		neighbour = getroomfromfarm(farm, endroom->linked[index]);
		revindex = neighbour->lvl;
		new_path = createpath(farm, neighbour->lvl + 2);
		while (revindex > 0)
		{
			new_path->roomsinpath[revindex] = ft_strdup(neighbour->name);
			neighbour = getroomfromfarm(farm, neighbour->visitedby);
			revindex--;
		}
		addpathtopaths(&farm->allpaths, new_path);
		index++;
	}
	sortpath(&farm->allpaths);
	clearpaths(&farm->allpaths);
}
