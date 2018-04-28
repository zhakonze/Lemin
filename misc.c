/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhakonze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:06:10 by zhakonze          #+#    #+#             */
/*   Updated: 2017/06/22 09:02:30 by zhakonze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"


t_room      *getroomfromfarm(t_antfarm *farm, char *room)
{
    t_room  *tempRoom;

    tempRoom = farm->allRooms;
    while (tempRoom != NULL)
    {
        if (ft_strequ(tempRoom->name, room) == 1)
            return (tempRoom);
        tempRoom = tempRoom->next;
    }
    return (tempRoom);
}

t_queue     *createQueueItem(char *name)
{
    t_queue     *item;

    if ((item = (t_queue*)malloc(sizeof(t_queue))) == NULL)
        return (NULL);
    else
    {
        item->name = ft_strdup(name);
        item->next = NULL;
        return (item);
    }
}

void        addToQueue(t_queue **queue, char *itemName)//we have double pointer for queue becuase we change its structure by adding another item
{
    t_queue     *tmp;

    if (*queue == NULL)
        *queue = createQueueItem(itemName);
    else
    {
        tmp = *queue;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = createQueueItem(itemName);
    }
}

void    removeFromQueue(t_queue **queue)
{
    t_queue *tmp;

    if (*queue != NULL)
    {
        tmp = *queue;
        *queue = (*queue)->next;
        free(tmp->name);
        tmp->name = NULL;
        free(tmp);
    }
}