/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2018/05/01 10:51:33 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*getroomfromfarm(t_antfarm *farm, char *room)
{
	t_room	*temproom;

	temproom = farm->allrooms;
	while (temproom != NULL)
	{
		if (ft_strequ(temproom->name, room) == 1)
			return (temproom);
		temproom = temproom->next;
	}
	return (temproom);
}

t_queue		*createqueueitem(char *name)
{
	t_queue	*item;

	if ((item = (t_queue*)malloc(sizeof(t_queue))) == NULL)
		return (NULL);
	else
	{
		item->name = ft_strdup(name);
		item->next = NULL;
		return (item);
	}
}

void		addtoqueue(t_queue **queue, char *itemname)
{
	t_queue	*tmp;

	if (*queue == NULL)
		*queue = createqueueitem(itemname);
	else
	{
		tmp = *queue;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = createqueueitem(itemname);
	}
}

void		removefromqueue(t_queue **queue)
{
	t_queue	*tmp;

	if (*queue != NULL)
	{
		tmp = *queue;
		*queue = (*queue)->next;
		free(tmp->name);
		tmp->name = NULL;
		free(tmp);
	}
}
